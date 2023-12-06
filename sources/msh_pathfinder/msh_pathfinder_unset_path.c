/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   msh_pathfinder_unset_path.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haekang <haekang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 18:04:47 by haekang           #+#    #+#             */
/*   Updated: 2023/12/06 16:29:55 by haekang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/msh.h"

char	*msh_pathfinder_unset_path(char *cmd)
{
	msh_pathfinder_is_dir(cmd);
	if (access(cmd, X_OK) == 0)
		return (cmd);
	write(2, "minishell: ", 11);
	write(2, cmd, msh_strlen(cmd));
	write(2, ": ", 2);
	write(2, strerror(errno), msh_strlen(strerror(errno)));
	write(2, "\n", 1);
	exit (127);
	return (NULL);
}
