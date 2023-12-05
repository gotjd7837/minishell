/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   msh_execute_pipeline.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haekang <haekang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 14:23:05 by jho               #+#    #+#             */
/*   Updated: 2023/12/05 17:03:05 by jho              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/msh_executor.h"
#include <string.h>

void	msh_execute_pipeline(int in, int out, char **param, t_env *env)
{
	char	*path;
	char	**envp;

	envp = msh_env_convert_arr(env);
	if (envp == NULL)
		msh_exit(errno);
	path = msh_pathfind(param[0], env);
	if (in != 0 && dup2(in, 0) == -1)
		exit(errno);
	if (out != 1 && dup2(out, 1) == -1)
		exit(errno);
	if (in != 0 && close(in) == -1)
		exit(errno);
	if (out != 1 && close(out) == -1)
		exit(errno);
	execve(path, param, envp);
	msh_exit(errno);
}
