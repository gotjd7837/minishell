/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   msh_execute_redir.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haeseong <haeseong@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 15:06:43 by jho               #+#    #+#             */
/*   Updated: 2024/06/13 21:11:47 by haeseong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/msh.h"

int	msh_execute_redir_read(char *val, int *fd)
{
	int		open_fd;
	char	*name;

	name = msh_substr(val, 1, msh_strlen(val));
	if (name == NULL)
		msh_exit(errno);
	name = msh_remove_whitespace(name);
	// infile open
	open_fd = open(name, O_RDONLY);
	if (open_fd == -1)
	{
		g_exit_status = 1;
		free(name);
		perror("msh");
		return (0);
	}
	// 입력 파일 디스크립터 설정
	fd[0] = open_fd;
	free(name);
	return (1);
}

int	msh_execute_redir_write(char *val, int *fd)
{
	int		open_fd;
	char	*name;

	name = msh_substr(val, 1, msh_strlen(val));
	if (name == NULL)
		msh_exit(errno);
	name = msh_remove_whitespace(name);
	// outfile open 또는 create
	open_fd = open(name, O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (open_fd == -1)
		msh_exit(errno);
	if (fd[1] != 1 && close(fd[1]) == -1)
		msh_exit(errno);
	// 출력 파일 디스크립터 설정
	fd[1] = open_fd;
	free(name);
	return (1);
}

int	msh_execute_redir_append(char *val, int *fd)
{
	int		open_fd;
	char	*name;

	name = msh_substr(val, 2, msh_strlen(val));
	if (name == NULL)
		msh_exit(errno);
	name = msh_remove_whitespace(name);
	open_fd = open(name, O_WRONLY | O_CREAT | O_APPEND, 0644);
	if (open_fd == -1)
		msh_exit(errno);
	if (fd[1] != 1 && close(fd[1]) == -1)
		msh_exit(errno);
	fd[1] = open_fd;
	free(name);
	return (1);
}

int	msh_execute_redir_filter(t_pipeline *pl, t_token *tk, int *fd, t_env *env)
{
	int	stat;

	// 토큰의 심볼이 REDIR 이면
	if (tk->sym == REDIR)
	{
		if (*(tk->val) == '<' && *(tk->val + 1) == '<')
		{
			stat = msh_execute_redir_hdoc(pl, tk->val, fd, env); // '<<' heredoc 처리
			if (stat != 1)
				return (0);
		}
		else if (*(tk->val) == '<'
			&& !msh_execute_redir_read(tk->val, fd)) // '<' 입력 처리
			return (0);
		else if (*(tk->val) == '>' && *(tk->val + 1) == '>')
		{
			if (!msh_execute_redir_append(tk->val, fd)) // '>>' 출력 처리
				return (0);
		}
		else if (*(tk->val) == '>')
		{
			if (!msh_execute_redir_write(tk->val, fd)) // '>' 출력 처리
				return (0);
		}
	}
	return (1);
}

int	msh_execute_redir(t_pipeline *pl, int *fd, t_env *env)
{
	t_token	*tokens;
	int		stat;

	// sigint(ctrl_c) 시그널 핸들러 변경
	signal(SIGINT, msh_handler_heredoc_ctrl_c);
	tokens = pl->tokens;
	while (tokens != NULL)
	{
		// 리다이렉션 수행
		stat = msh_execute_redir_filter(pl, tokens, fd, env);
		if (stat != 1)
			return (stat);
		tokens = tokens->next;
	}
	return (1);
}
