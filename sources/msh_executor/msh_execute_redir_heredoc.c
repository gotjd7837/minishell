/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   msh_execute_redir_heredoc.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haekang <haekang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/25 00:34:28 by jho               #+#    #+#             */
/*   Updated: 2023/12/01 16:11:51 by haekang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/msh_executor.h"
#include "../../includes/msh_signal.h"

int	msh_execute_redir_heredoc_strcmp(char *s1, char *s2)
{
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

	signal(SIGINT, msh_execute_redir_heredoc_child_signal);
	signal(SIGQUIT, SIG_IGN);
	while (1)
	{
		write(1, "> ", 2);
		line = get_next_line(0);
		if (line == NULL)
		{
			free(limiter);
			break ;
		}
		if (msh_execute_redir_heredoc_strcmp(line, limiter) == 0)
		{
			free(line);
			break ;
		}
		expanded = msh_expand_heredoc(line, env);
		write(fd, expanded, msh_strlen(expanded));
		free(line);
	}
	exit(1);
}

int	msh_execute_redir_heredoc_input(char *limiter, int fd, t_env *env)
{
	int		stat;
	pid_t	pid;

	signal(SIGQUIT, SIG_IGN);
	pid = fork();
	if (pid == -1)
		return (0);
	else if (pid == 0)
		msh_heredoc(limiter, fd, env);
	if (waitpid(pid, &stat, 0) == -1)
		return (0);
	if (WEXITSTATUS(stat) == 0)
	{
		g_exit_status = -1;
		signal(SIGQUIT, msh_handler_blocking_ctrl_slash);
		return (-1);
	}
	signal(SIGQUIT, msh_handler_blocking_ctrl_slash);
	return (1);
}

int	msh_execute_redir_heredoc(t_pipeline *pl, char *lim, int *fd, t_env *env)
{
	char	*name;
	int		stat;

	lim = msh_substr(lim, 2, msh_strlen(lim));
	lim = msh_remove_whitespace(lim);
	if (lim == NULL)
		return (0);
	name = msh_execute_mktemp();
	if (fd[0] != 0 && close(fd[0]) == -1)
		return (0);
	fd[0] = open(name, O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (fd[0] == -1)
		return (0);
	msh_pipeline_add_heredoc(pl, msh_heredoc_malloc(fd[0], name));
	stat = msh_execute_redir_heredoc_input(lim, fd[0], env);
	free(lim);
	if (close(fd[0]) == -1)
		return (0);
	if (stat != -1)
	{
		fd[0] = open(name, O_RDONLY);
		if (fd[0] == -1)
			return (0);
	}
	return (stat);
}
