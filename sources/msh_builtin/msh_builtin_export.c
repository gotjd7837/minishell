/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   msh_builtin_export.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haekang <haekang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/27 21:49:34 by haekang           #+#    #+#             */
/*   Updated: 2023/12/05 19:33:07 by haekang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/msh.h"

int	msh_builtin_export(int *fd, int pipe, char **cmd, t_env *env)
{
	int	i;
	int	argc;

	i = 1;
	argc = 0;
	g_exit_status = 0;
	while (cmd[argc] != NULL)
		argc++;
	if (argc == 1)
		msh_export_print(env, fd[1]);
	while (i < argc)
	{
		if (!msh_export_create(cmd[i++], env))
		{
			g_exit_status = 1;
			if (pipe == 1)
				exit (g_exit_status);
		}
	}
	if (pipe == 1)
		exit (g_exit_status);
	return (0);
}
