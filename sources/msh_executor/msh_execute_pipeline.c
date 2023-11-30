/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   msh_execute_pipeline.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haekang <haekang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 14:23:05 by jho               #+#    #+#             */
/*   Updated: 2023/11/30 16:37:14 by jho              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/msh_executor.h"
#include <string.h>

void	msh_execute_pipeline(int in, int out, char **param, t_env *env)
{
	char	*path;
	char	**envp;

	if (in != 0 && dup2(in, 0) == -1)
		exit(errno);
	if (out != 1 && dup2(out, 1) == -1)
		exit(errno);
	if (in != 0 && close(in) == -1)
		exit(errno);
	if (out != 1 && close(out) == -1)
		exit(errno);
	envp = msh_env_convert_arr(env);
	if (envp == NULL)
		exit(errno);
	path = msh_pathfind(param[0], env);
	if (path == NULL)
	{
		printf("command not found\n");
		exit(errno);
	}
	execve(path, param, envp);
	exit(errno);
}
