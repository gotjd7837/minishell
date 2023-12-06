/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   msh_pathfinder.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haekang <haekang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/03 15:44:27 by jho               #+#    #+#             */
/*   Updated: 2023/12/06 17:40:47 by haekang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/msh.h"

char	*msh_pathfinder(char *cmd, t_env *env)
{
	char	**path;
	char	*cmd_path;

	path = msh_pathfinder_find_env_path(env);
	cmd_path = msh_pathfinder_find_cmd_abspath(path, cmd);
	if (*cmd == '\0')
		cmd_path = NULL;
	if (cmd_path == NULL)
	{
		write(2, "minishell: ", 11);
		write(2, cmd, msh_strlen(cmd));
		write(2, ": command not found\n", 20);
		exit(127);
	}
	return (cmd_path);
}
