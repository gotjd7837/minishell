/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   msh_find_cmd_abspath.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haekang <haekang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/03 17:20:31 by haekang           #+#    #+#             */
/*   Updated: 2023/11/03 17:54:20 by haekang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/msh_pathfinder.h"

char	*msh_find_cmd_abspath(char **path, char *cmd)
{
	int		i;
	char	*slash_cmd;
	char	*cmd_path;

	if (msh_is_path(cmd) == 1)
		return (msh_check_cmd_exist(cmd));
	i = 0;
	slash_cmd = msh_strjoin("/", cmd);
	if (slash_cmd == NULL)
		return (NULL);
	while (path[i] != NULL)
	{
		cmd_path = msh_strjoin(path[i], slash_cmd);
		if (access(cmd_path, X_OK) == 0)
		{
			free(slash_cmd);
			return (cmd_path);
		}
		free(cmd_path);
		i++;
	}
	return (NULL);
}
