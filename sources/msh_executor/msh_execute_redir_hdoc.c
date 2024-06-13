/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   msh_execute_redir_hdoc.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haekang <haekang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/25 00:34:28 by jho               #+#    #+#             */
/*   Updated: 2023/12/05 16:30:24 by jho              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/msh.h"

// heredoc 리미터 확인 strcmp
int	msh_execute_redir_hdoc_strcmp(char *s1, char *s2)
{
	if (*s1 == '\n')
		return (1);
	while (*s1 != '\n' && *s1 != '\0')
	{
		if (*s1 != *s2)
			break ;
		s1++;
		s2++;
	}
	if (*s1 == '\n')
		return (0);
	return (*s1 - *s2);
}

void	msh_execute_redir_heredoc_child_signal(int num)
{
	num = 0;
	exit(0);
}

void	msh_heredoc(char *limiter, int fd, t_env *env)
{
	char	*expanded;
	char	*line;

	// ctrl_c, ctrl_\\ 시그널 핸들러 설정
	signal(SIGINT, msh_execute_redir_heredoc_child_signal);
	signal(SIGQUIT, SIG_IGN);
	while (1)
	{
		write(1, "> ", 2); // 프롬프트 출력
		line = get_next_line(0); // 사용자 입력 받기
		if (line == NULL)
		{
			free(limiter);
			break ;
		}
		if (msh_execute_redir_hdoc_strcmp(line, limiter) == 0) // 입력이 리미터랑 일치하면 종료
		{
			free(line);
			break ;
		}
		expanded = msh_expand_heredoc(line, env); // 환경변수 확장
		if (write(fd, expanded, msh_strlen(expanded)) == -1)
			msh_exit(errno);
		free(line);
	}
	exit(1);
}

int	msh_execute_redir_hdoc_input(char *limiter, int fd, t_env *env)
{
	int		stat;
	pid_t	pid;

	// 자식 프로세스 생성
	pid = fork();
	if (pid == -1)
		msh_exit(errno);
	else if (pid == 0)
		msh_heredoc(limiter, fd, env); // 자식 프로세스에서 heredoc 처리
	if (waitpid(pid, &stat, 0) == -1)
		msh_exit(errno);
	if (WEXITSTATUS(stat) == 0)
	{
		g_exit_status = -1;
		return (-1);
	}
	return (1);
}

int	msh_execute_redir_hdoc(t_pipeline *pl, char *lim, int *fd, t_env *env)
{
	char	*name;
	int		stat;

	lim = msh_substr(lim, 2, msh_strlen(lim));
	if (lim == NULL)
		msh_exit(errno);
	lim = msh_remove_whitespace(lim);
	name = msh_execute_mktemp(); // 임시 파일 이름 생성
	if (fd[0] != 0 && close(fd[0]) == -1)
		msh_exit(errno);
	fd[0] = open(name, O_WRONLY | O_CREAT | O_TRUNC, 0644); // 임시 파일 생성
	if (fd[0] == -1)
		msh_exit(errno);
	msh_pipeline_add_heredoc(pl, msh_heredoc_malloc(fd[0], name));
	stat = msh_execute_redir_hdoc_input(lim, fd[0], env); // heredoc 입력 처리
	free(lim);
	if (close(fd[0]) == -1)
		return (0);
	if (stat != -1)
	{
		fd[0] = open(name, O_RDONLY);
		if (fd[0] == -1)
			msh_exit(errno);
	}
	return (stat);
}
