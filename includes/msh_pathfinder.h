/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   msh_pathfinder.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haekang <haekang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/03 15:49:38 by haekang           #+#    #+#             */
/*   Updated: 2023/11/03 17:54:08 by haekang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MSH_PATHFINDER_H
# define MSH_PATHFINDER_H
# include "msh_env.h"

char	*msh_pathfind(char *cmd, t_env *env);
char	**msh_find_env_path(t_env *env);
char	*msh_find_cmd_abspath(char **path, char *cmd);
int		msh_is_path(char *cmd);
char	*msh_check_cmd_exist(char *cmd);

#endif
