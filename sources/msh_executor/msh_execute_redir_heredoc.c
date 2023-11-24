/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   msh_execute_redir_heredoc.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jho <jho@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/25 00:34:28 by jho               #+#    #+#             */
/*   Updated: 2023/11/25 00:51:20 by jho              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/msh_executor.h"

int	msh_execute_redir_heredoc_strcmp(char *limiter, char *line)
{
	while (*s1 == *(s2++))
	{
		if (*(s1++) == '\n')
			return (0);
	}
	return (*s1 - *(s2 - 1));
}

int	msh_execute_redir_heredoc(char *limiter, int *fd)
{
	char *line;

	fd[0] = open("HEREDOC", O_RDWR | O_CREAT | O_TRUNC, 0644);
	while (1)
	{
		write(1, "> ", 2);
		line = get_next_line(0);
		if (line == NULL)
			break ;
		if (msh_execute_redir_heredoc_strcmp(limiter, line) == 0)
			break ;
		write(fd[0], line, msh_strlen(line));
		free(line);
	}
}
