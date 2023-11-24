/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   msh_execute_redir_heredoc.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jho <jho@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/25 00:34:28 by jho               #+#    #+#             */
/*   Updated: 2023/11/25 03:32:14 by jho              ###   ########.fr       */
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

int	msh_execute_redir_heredoc(char *limiter, int *fd, char *heredoc_list)
{
	char	*line;
	char	*name;

	limiter = msh_substr(limiter, 2, msh_strlen(limiter));
	name = msh_execute_mktemp();
	fd[4] = open(heredoc_list, O_WRONLY | O_APPEND);
	write(fd[4], name, msh_strlen(name));
	write(fd[4], "\n", 1);
	close(fd[4]);
	fd[0] = open(name, O_WRONLY | O_CREAT | O_TRUNC, 0644);
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
			break ;
		write(fd[0], line, msh_strlen(line));
		free(line);
	}
	free(limiter);
	close(fd[0]);
	fd[0] = open(name, O_RDONLY);
	return (1);
}
