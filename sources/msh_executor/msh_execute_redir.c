/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   msh_execute_redir.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jho <jho@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 15:06:43 by jho               #+#    #+#             */
/*   Updated: 2023/12/01 15:54:49 by jho              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/msh_executor.h"

int	msh_execute_redir_read(char *val, int *fd)
{
	int		open_fd;
	char	*name;

	name = msh_substr(val, 1, msh_strlen(val));
	name = msh_remove_whitespace(name);
	if (name == NULL)
		return (0);
	open_fd = open(name, O_RDONLY);
	if (open_fd == -1)
		return (0);
	fd[0] = open_fd;
	free(name);
	return (1);
}

int	msh_execute_redir_write(char *val, int *fd)
{
	int		open_fd;
	char	*name;

	name = msh_substr(val, 1, msh_strlen(val));
	name = msh_remove_whitespace(name);
	if (name == NULL)
		return (0);
	open_fd = open(name, O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (open_fd == -1)
		return (0);
	if (fd[1] != 1 && close(fd[1]) == -1)
		return (0);
	fd[1] = open_fd;
	free(name);
	return (1);
}

int	msh_execute_redir_append(char *val, int *fd)
{
	int		open_fd;
	char	*name;

	name = msh_substr(val, 2, msh_strlen(val));
	name = msh_remove_whitespace(name);
	if (name == NULL)
		return (0);
	open_fd = open(name, O_WRONLY | O_CREAT | O_APPEND, 0644);
	if (open_fd == -1)
		return (0);
	if (fd[1] != 1 && close(fd[1]) == -1)
		return (0);
	fd[1] = open_fd;
	free(name);
	return (1);
}

int	msh_execute_redir_filter(t_pipeline *pl, t_token *tk, int *fd, t_env *env)
{
	int	stat;

	if (tk->sym == REDIR)
	{
		if (*(tk->val) == '<' && *(tk->val + 1) == '<')
		{
			stat = msh_execute_redir_heredoc(pl, tk->val, fd, env);
			if (stat != 1)
				return (0);
		}
		else if (*(tk->val) == '<'
			&& !msh_execute_redir_read(tk->val, fd))
			return (0);
		else if (*(tk->val) == '>' && *(tk->val + 1) == '>')
		{
			if (!msh_execute_redir_append(tk->val, fd))
				return (0);
		}
		else if (*(tk->val) == '>')
		{
			if (!msh_execute_redir_write(tk->val, fd))
				return (0);
		}
	}
	return (1);
}

int	msh_execute_redir(t_pipeline *pl, int *fd, t_env *env)
{
	t_token	*tokens;
	int		stat;

	tokens = pl->tokens;
	while (tokens != NULL)
	{
		stat = msh_execute_redir_filter(pl, tokens, fd, env);
		if (stat != 1)
			return (stat);
		tokens = tokens->next;
	}
	return (1);
}
