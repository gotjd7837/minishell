/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   msh_execute_pipeline.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jho <jho@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 14:23:05 by jho               #+#    #+#             */
/*   Updated: 2023/11/23 18:13:21 by jho              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/msh_executor.h"
#include <stdio.h>

void	msh_execute_pipeline(int in, int out, char **param, t_env *env)
{
	if (in != 0 && dup2(in, 0) == -1)
		exit(errno);
	if (out != 1 && dup2(out, 1) == -1)
		exit(errno);
	if (in != 0 && close(in) == -1)
		exit(errno);
	if (out != 1 && close(out) == -1)
		exit(errno);
	execve(msh_pathfind(param[0], env), param, NULL);
	exit(errno);
}
