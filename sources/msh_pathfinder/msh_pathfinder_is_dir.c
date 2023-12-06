/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   msh_pathfinder_is_dir.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haekang <haekang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 17:52:39 by haekang           #+#    #+#             */
/*   Updated: 2023/12/06 16:35:35 by haekang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/msh.h"

int	msh_pathfinder_is_dir(char *path)
{
	struct stat	path_stat;

	stat(path, &path_stat);
	if (S_ISDIR(path_stat.st_mode) == 1)
	{
		write(2, "minishell: ", 11);
		write(2, path, msh_strlen(path));
		write(2, ": is a directory\n", 17);
		exit (126);
	}
	return (S_ISDIR(path_stat.st_mode));
}
