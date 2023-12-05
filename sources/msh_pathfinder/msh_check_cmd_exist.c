/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   msh_check_cmd_exist.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haekang <haekang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/03 17:24:08 by haekang           #+#    #+#             */
/*   Updated: 2023/12/05 17:09:46 by haekang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/msh_pathfinder.h"
#include <stdio.h>
#include <errno.h>
#include <string.h>
#include <sys/stat.h>

int	is_directory(const char *path)
{
	struct stat	path_stat;

	stat(path, &path_stat);
	return (S_ISDIR(path_stat.st_mode));
}

char	*msh_check_cmd_exist(char *cmd)
{
	if (is_directory(cmd) == 1)
	{
		printf("minishell: %s: is a directory\n", cmd);
		exit (126);
	}
	if (access(cmd, X_OK) == 0)
		return (cmd);
	printf("minishell: %s: %s\n", cmd, strerror(errno));
	exit (errno);
	return (NULL);
}
