/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   msh_execute_redir_heredoc.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jho <jho@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/25 00:34:28 by jho               #+#    #+#             */
/*   Updated: 2023/11/29 19:47:27 by jho              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/msh_executor.h"

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

int	msh_execute_redir_heredoc(t_pipeline *pl, char *limiter, int *fd)
{
	char	*line;
	char	*name;

	limiter = msh_substr(limiter, 2, msh_strlen(limiter));
	if (limiter == NULL)
		return (0);
	name = msh_execute_mktemp();
	if (fd[0] != 0 && close(fd[0]) == -1)
		return (0);
	fd[0] = open(name, O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (fd[0] == -1)
		return (0);
	msh_pipeline_add_heredoc(pl, msh_heredoc_malloc(fd[0], name));
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
		write(fd[0], line, msh_strlen(line));
		free(line);
	}
	free(limiter);
	if (close(fd[0]) == -1)
		return (0);
	fd[0] = open(name, O_RDONLY);
	if (fd[0] == -1)
		return (0);
	return (1);
}
