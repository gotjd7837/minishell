/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   msh_execute.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haekang <haekang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 11:55:04 by jho               #+#    #+#             */
/*   Updated: 2023/12/05 19:34:50 by haekang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/msh.h"

int	msh_execute_wait_children(t_pipeline *pl, int status)
{
	int	child_status;
	int	is_signal;

	if (g_exit_status == -1)
	{
		is_signal = 1;
		g_exit_status = 1;
	}
	else
		is_signal = 0;
	while (pl != NULL && pl->pid != -1)
	{
		if (waitpid(pl->pid, &child_status, 0) == -1)
			msh_exit(errno);
		if (!is_signal)
			g_exit_status = WEXITSTATUS(child_status);
		pl = pl->next;
	}
	return (status);
}

int	msh_execute_single(t_pipeline *pipelines, int *fd, t_env *env)
{
	int	children_num;

	fd[0] = 0;
	fd[1] = 1;
	children_num = msh_execute_first(pipelines, fd, env, UNFORKED);
	if (children_num == -1)
		return (0);
	return (1);
}

int	msh_execute_single_fork(t_pipeline *pl, int *fd, t_env *env)
{
	int	children_num;

	children_num = msh_execute_first(pl, fd, env, FORKED);
	if (children_num == -1)
		return (0);
	return (1);
}

int	msh_execute_multiple(t_pipeline *pl, int *fd, t_env *env)
{
	int	children_num;

	if (pl->next->next != NULL)
	{
		children_num = msh_execute_middle(pl->next, fd, env);
		if (children_num == -1)
			return (0);
	}
	return (1);
}

int	msh_execute(t_pipeline *pl, t_env *env)
{
	int			stat;
	int			fd[4];

	if (pl->next == NULL)
	{
		if (!msh_execute_single(pl, fd, env))
			return (msh_execute_wait_children(pl, 0));
	}
	else
	{
		if (pipe(fd) == -1)
			return (0);
		if (!msh_execute_single_fork(pl, fd, env))
			return (msh_execute_wait_children(pl, 0));
		if (!msh_execute_multiple(pl, fd, env))
			return (msh_execute_wait_children(pl, 0));
		stat = msh_execute_last(msh_pipeline_last(pl), fd, env);
		if (stat == -1)
			return (msh_execute_wait_children(pl, 0));
	}
	return (msh_execute_wait_children(pl, 1));
}
