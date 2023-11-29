/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   msh_execute_middle.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jho <jho@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 14:24:44 by jho               #+#    #+#             */
/*   Updated: 2023/11/29 16:15:59 by jho              ###   ########.fr       */
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

void	msh_execute_middle_child(t_pipeline *pl, int *fd, t_env *env)
{
	char	**param;

	param = msh_token_filter_sym(pl->tokens, WORD);
	if (param == NULL)
		exit(errno);
	msh_execute_pipeline(fd[0], fd[1], param, env);
}

int	msh_execute_middle(t_pipeline *pl, int *fd, t_env *env)
{
	pid_t	pid;
	int		children_num;
	int		fd_cp[4];

	children_num = 0;
	while (pl->next != NULL)
	{
		if (pipe(fd + 2) == -1)
			return (children_num);
		else
		{
			fd_cp[0] = fd[0];
			fd_cp[1] = fd[3];
			if (!msh_execute_redir(pl, fd_cp))
				return (0);
			pid = fork();
			if (pid == -1)
				return (children_num);
			if (pid == 0)
			{
				if (close(fd[1]) == -1 || close(fd[2]) == -1)
					return (0);
				if (msh_execute_check_builtin(pl))
					msh_execute_middle_builtin(pl, fd_cp, env);
				else
					msh_execute_middle_child(pl, fd_cp, env);
			}
			++children_num;
		}
		if (!msh_execute_pipe_shift(fd))
			return (children_num);
		pl = pl->next;
	}
	return (children_num);
}
