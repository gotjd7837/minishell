/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   msh_pathfinder_unset_path.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haekang <haekang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 18:04:47 by haekang           #+#    #+#             */
/*   Updated: 2023/12/05 19:37:12 by haekang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/msh.h"

char	*msh_pathfinder_unset_path(char *cmd)
{
	msh_pathfinder_is_dir(cmd);
	if (access(cmd, X_OK) == 0)
		return (cmd);
	printf("minishell: %s: %s\n", cmd, strerror(errno));
	exit (127);
	return (NULL);
}
