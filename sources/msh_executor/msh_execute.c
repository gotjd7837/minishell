/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   msh_execute.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jho <jho@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 11:55:04 by jho               #+#    #+#             */
/*   Updated: 2023/11/23 18:24:12 by jho              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/msh_executor.h"
#include <stdio.h>

int	msh_execute(t_pipeline *pipelines, t_env *env)
{
	int		children_num;
	int		fd[4];

	children_num = 0;
	if (pipelines->next == NULL)
	{
		fd[0] = 0;
		fd[1] = 1;
		children_num += msh_execute_first(pipelines, fd, env);
	}
	else
	{
		if (pipe(fd) == -1)
			return (0);
		children_num += msh_execute_first(pipelines, fd, env);
		if (pipelines->next->next != NULL)
			children_num += msh_execute_middle(pipelines->next, fd, env);
		children_num += msh_execute_last(msh_pipeline_last(pipelines), fd, env);
	}
	while (--children_num > -1)
	{
		if (wait(&g_exit_status) == -1)
			return (0);
		g_exit_status = WEXITSTATUS(g_exit_status);
	}
	printf("Exit status : %d\n", g_exit_status);
	return (1);
}
