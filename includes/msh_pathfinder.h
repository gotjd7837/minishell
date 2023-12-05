/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   msh_pathfinder.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haekang <haekang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/03 15:49:38 by haekang           #+#    #+#             */
/*   Updated: 2023/12/05 18:13:15 by haekang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MSH_PATHFINDER_H
# define MSH_PATHFINDER_H
# include <stdio.h>
# include <errno.h>
# include <sys/stat.h>
# include <string.h>
# include "msh_env.h"

char	*msh_pathfinder(char *cmd, t_env *env);
char	*msh_pathfinder_unset_path(char *cmd);
int		msh_pathfinder_is_path(char *cmd);
int		msh_pathfinder_is_dir(const char *path);
char	**msh_pathfinder_find_env_path(t_env *env);
char	*msh_pathfinder_find_cmd_abspath(char **path, char *cmd);
char	*msh_pathfinder_check_path_exist(char *cmd);

#endif
