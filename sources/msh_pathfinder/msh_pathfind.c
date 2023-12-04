/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   msh_pathfind.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haekang <haekang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/03 15:44:27 by jho               #+#    #+#             */
/*   Updated: 2023/12/04 20:04:34 by haekang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/msh_pathfinder.h"
#include <stdio.h>
#include <errno.h>
#include <string.h>
#include <sys/stat.h>
char	*msh_pathfind(char *cmd, t_env *env)
{
	char	**path;
	char	*cmd_path;

	path = msh_find_env_path(env);
	cmd_path = msh_find_cmd_abspath(path, cmd);
	if (cmd_path == NULL)
	{
		printf("minishell: %s: %s\n", cmd, strerror(errno));
		exit (errno);
	}
	return (cmd_path);
}
