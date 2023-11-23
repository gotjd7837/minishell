/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   msh_execute.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jho <jho@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 11:55:04 by jho               #+#    #+#             */
/*   Updated: 2023/11/23 14:36:00 by jho              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/msh_executor.h"

int	msh_execute(t_pipeline *pipelines, t_env *env)
{
	int		children_num;
	int		fd[4];

	children_num = 0;
	if (pipelines->next == NULL)
	{
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
		if (wait(0) == -1)
			return (0);
	return (1);
}
