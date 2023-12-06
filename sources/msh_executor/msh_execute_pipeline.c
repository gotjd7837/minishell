/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   msh_execute_pipeline.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haekang <haekang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 14:23:05 by jho               #+#    #+#             */
/*   Updated: 2023/12/06 17:36:56 by haekang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/msh.h"

void	msh_execute_pipeline(int in, int out, char **param, t_env *env)
{
	char	*path;
	char	**envp;

	envp = msh_env_convert_arr(env);
	if (envp == NULL)
		msh_exit(errno);
	path = msh_pathfinder(param[0], env);
	if (in != 0 && dup2(in, 0) == -1)
		exit(errno);
	if (out != 1 && dup2(out, 1) == -1)
		exit(errno);
	if (in != 0 && close(in) == -1)
		exit(errno);
	if (out != 1 && close(out) == -1)
		exit(errno);
	if (execve(path, param, envp) == -1)
	{
		printf("minishell: %s: %s\n", param[0], strerror(errno));
		exit (errno);
	}
	msh_exit(errno);
}
