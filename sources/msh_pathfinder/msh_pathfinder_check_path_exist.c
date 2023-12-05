/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   msh_pathfinder_check_path_exist.c                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haekang <haekang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/03 17:24:08 by haekang           #+#    #+#             */
/*   Updated: 2023/12/05 18:03:16 by haekang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/msh_pathfinder.h"
#include <stdio.h>
#include <errno.h>
#include <string.h>
#include <sys/stat.h>

char	*msh_pathfinder_check_path_exist(char *cmd)
{
	msh_pathfinder_is_dir(cmd);
	if (access(cmd, X_OK) == 0)
		return (cmd);
	printf("minishell: %s: %s\n", cmd, strerror(errno));
	exit (127);
	return (NULL);
}
