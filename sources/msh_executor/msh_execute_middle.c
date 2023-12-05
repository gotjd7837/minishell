/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   msh_execute_middle.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haekang <haekang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 14:24:44 by jho               #+#    #+#             */
/*   Updated: 2023/12/05 19:34:22 by haekang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/msh.h"

int	msh_execute_middle_builtin(t_pipeline *pl, int *fd, t_env *env)
{
	char	**param;

	param = msh_token_filter_sym(pl->tokens, WORD);
	if (param == NULL)
		msh_exit(errno);
	return (msh_execute_builtin(fd, param, env, 1));
}

void	msh_execute_middle_no_builtin(t_pipeline *pl, int *fd, t_env *env)
{
	char	**param;

	param = msh_token_filter_sym(pl->tokens, WORD);
	if (param == NULL)
		msh_exit(errno);
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

int	msh_execute_middle(t_pipeline *pl, int *fd, t_env *env)
{
	int		local_fd[4];

	while (pl->next != NULL)
	{
		if (pipe(fd + 2) == -1)
			return (-1);
		else
		{
			local_fd[0] = fd[0];
			local_fd[1] = fd[3];
			if (msh_execute_redir(pl, local_fd, env) != 1)
				return (-1);
			pl->pid = fork();
			if (pl->pid == -1)
				msh_exit(errno);
			if (pl->pid == 0)
				msh_execute_middle_child(pl, fd, local_fd, env);
		}
		if (!msh_execute_pipe_shift(fd, local_fd))
			msh_exit(errno);
		pl = pl->next;
	}
	return (1);
}
