/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   msh_builtin_cd_chdir.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haekang <haekang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 16:14:44 by haekang           #+#    #+#             */
/*   Updated: 2023/12/06 15:55:09 by haekang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/msh.h"

int	msh_builtin_cd_chdir(char *path, char *old_pwd, int pipe)
{
	if (chdir(path))
	{
		if (old_pwd != NULL)
			free(old_pwd);
		write(2, "minishell: cd: ", 15);
		write(2, path, msh_strlen(path));
		write(2, ": No such file or directory\n", 28);
		g_exit_status = 1;
		if (pipe == 1)
			exit (g_exit_status);
		return (0);
	}
	return (1);
}
