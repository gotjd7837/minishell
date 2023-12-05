/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   msh_pathfinder.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haekang <haekang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/03 15:44:27 by jho               #+#    #+#             */
/*   Updated: 2023/12/05 18:12:14 by haekang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/msh_pathfinder.h"

char	*msh_pathfinder(char *cmd, t_env *env)
{
	char	**path;
	char	*cmd_path;

	path = msh_pathfinder_find_env_path(env);
	cmd_path = msh_pathfinder_find_cmd_abspath(path, cmd);
	if (cmd_path == NULL)
	{
		printf("minishell: %s: command not found\n", cmd);
		exit(127);
	}
	return (cmd_path);
}
