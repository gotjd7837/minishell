/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   msh_pathfinder_is_dir.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haekang <haekang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 17:52:39 by haekang           #+#    #+#             */
/*   Updated: 2023/12/05 19:37:05 by haekang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/msh.h"

int	msh_pathfinder_is_dir(const char *path)
{
	struct stat	path_stat;

	stat(path, &path_stat);
	if (S_ISDIR(path_stat.st_mode) == 1)
	{
		printf("minishell: %s: is a directory\n", path);
		exit (126);
	}
	return (S_ISDIR(path_stat.st_mode));
}
