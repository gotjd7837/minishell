/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   msh_execute_last.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jho <jho@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 14:25:16 by jho               #+#    #+#             */
/*   Updated: 2023/11/23 15:34:05 by jho              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/msh_executor.h"
#include <stdio.h>

int	msh_execute_last(t_pipeline *pl, int *fd, t_env *env)
{
	pid_t	pid;
	char	**param;

	pid = fork();
	if (pid == -1)
		return (0);
	else if (pid == 0)
	{
		if (fd[1] != 1 && close(fd[1]) == -1)
			exit(errno);
		fd[1] = 1;
		param = msh_token_filter_sym(pl->tokens, WORD);
		if (!msh_execute_redir(pl->tokens, fd))
			exit(errno);
		if (param == NULL)
			exit(errno);
		msh_execute_pipeline(fd[0], fd[1], param, env);
	}
	close(fd[0]);
	close(fd[1]);
	return (1);
}
