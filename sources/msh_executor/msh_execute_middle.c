/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   msh_execute_middle.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jho <jho@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 14:24:44 by jho               #+#    #+#             */
/*   Updated: 2023/11/30 16:20:01 by jho              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/msh_executor.h"

int	msh_execute_middle_builtin(t_pipeline *pl, int *fd, t_env *env)
{
	char	**param;

	param = msh_token_filter_sym(pl->tokens, WORD);
	if (param == NULL)
		exit(errno);
	return (msh_execute_builtin(fd, param, env, 1));
}

void	msh_execute_middle_no_builtin(t_pipeline *pl, int *fd, t_env *env)
{
	char	**param;

	param = msh_token_filter_sym(pl->tokens, WORD);
	if (param == NULL)
		exit(errno);
	msh_execute_pipeline(fd[0], fd[1], param, env);
}

void	msh_execute_middle_child(t_pipeline *pl, int *fd1, int *fd2, t_env *env)
{
	close(fd1[1]);
	close(fd1[2]);
	if (msh_execute_check_builtin(pl))
		msh_execute_middle_builtin(pl, fd2, env);
	else
		msh_execute_middle_no_builtin(pl, fd2, env);
}

int	msh_execute_middle(t_pipeline *pl, int *fd, t_env *env, int *total)
{
	pid_t	pid;
	int		local_fd[4];

	while (pl->next != NULL)
	{
		if (pipe(fd + 2) == -1)
			return (-1);
		else
		{
			local_fd[0] = fd[0];
			local_fd[1] = fd[3];
			if (msh_execute_redir(pl, local_fd) != 1)
				return (-1);
			pid = fork();
			if (pid == -1)
				return (-1);
			if (pid == 0)
				msh_execute_middle_child(pl, fd, local_fd, env);
			++(*total);
		}
		if (!msh_execute_pipe_shift(fd, local_fd))
			return (-1);
		pl = pl->next;
	}
	return (1);
}
