/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   msh_execute_redir.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jho <jho@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 15:06:43 by jho               #+#    #+#             */
/*   Updated: 2023/11/23 16:08:15 by jho              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/msh_executor.h"
#include <stdio.h>

int	msh_execute_redir_read(char *val, int *fd)
{
	int		open_fd;
	char	*name;

	name = msh_substr(val, 1, msh_strlen(val));
	if (name == NULL)
		return (0);
	open_fd = open(name, O_RDONLY);
	if (open_fd == -1 || close(fd[0]) == -1)
		return (0);
	fd[0] = open_fd;
	return (1);
}

int	msh_execute_redir_write(char *val, int *fd)
{
	int		open_fd;
	char	*name;

	name = msh_substr(val, 1, msh_strlen(val));
	if (name == NULL)
		return (0);
	printf("called\n");
	open_fd = open(name, O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (open_fd == -1 || close(fd[1]) == -1)
		return (0);
	fd[1] = open_fd;
	return (1);
}

int	msh_execute_redir_append(char *val, int *fd)
{
	int		open_fd;
	char	*name;

	name = msh_substr(val, 2, msh_strlen(val));
	if (name == NULL)
		return (0);
	open_fd = open(name, O_WRONLY | O_CREAT | O_APPEND, 0644);
	if (open_fd == -1 || close(fd[1]) == -1)
		return (0);
	fd[1] = open_fd;
	return (1);
}

int	msh_execute_redir(t_token *tokens, int *fd)
{
	while (tokens != NULL)
	{
		if (tokens->sym == REDIR)
		{
			if (*(tokens->val) == '<')
			{
				if (!msh_execute_redir_read(tokens->val, fd))
					return (0);
			}
			else if (*(tokens->val) == '>' && *(tokens->val + 1) == '>')
			{
				if (!msh_execute_redir_append(tokens->val, fd))
					return (0);
			}
			else if (*(tokens->val) == '>')
			{
				if (!msh_execute_redir_write(tokens->val, fd))
					return (0);
			}
		}
		tokens = tokens->next;
	}
	return (1);
}
