/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   msh_execute.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jho <jho@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 11:55:04 by jho               #+#    #+#             */
/*   Updated: 2023/12/05 11:10:50 by jho              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/msh_executor.h"

int	msh_execute_wait_children(int children_num, int status)
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
	while (--children_num > -1)
	{
		if (wait(&child_status) == -1)
			msh_exit(errno);
		if (is_signal)
			g_exit_status = WEXITSTATUS(child_status);
	}
	return (status);
}

int	msh_execute_single(t_pipeline *pipelines, int *fd, t_env *env, int *total)
{
	int	children_num;

	fd[0] = 0;
	fd[1] = 1;
	children_num = msh_execute_first(pipelines, fd, env, UNFORKED);
	if (children_num == -1)
		return (msh_execute_wait_children(*total, 0));
	else
		*total += children_num;
	return (1);
}

int	msh_execute_single_fork(t_pipeline *pl, int *fd, t_env *env, int *total)
{
	int	children_num;

	children_num = msh_execute_first(pl, fd, env, FORKED);
	if (children_num == -1)
		return (msh_execute_wait_children(*total, 0));
	else
		*total += children_num;
	return (1);
}

int	msh_execute_multiple(t_pipeline *pl, int *fd, t_env *env, int *total)
{
	int	children_num;

	if (pl->next->next != NULL)
	{
		children_num = msh_execute_middle(pl->next, fd, env, total);
		if (children_num == -1)
			return (msh_execute_wait_children(*total, 0));
	}
	return (1);
}

int	msh_execute(t_pipeline *pipelines, t_env *env)
{
	int			children_num;
	int			total_children;
	int			fd[4];

	total_children = 0;
	if (pipelines->next == NULL)
	{
		if (!msh_execute_single(pipelines, fd, env, &total_children))
			return (0);
	}
	else
	{
		if (pipe(fd) == -1)
			return (0);
		if (!msh_execute_single_fork(pipelines, fd, env, &total_children))
			return (0);
		if (!msh_execute_multiple(pipelines, fd, env, &total_children))
			return (0);
		children_num = msh_execute_last(msh_pipeline_last(pipelines), fd, env);
		if (children_num == -1)
			return (msh_execute_wait_children(total_children, 0));
		else
			total_children += children_num;
	}
	return (msh_execute_wait_children(total_children, 1));
}
