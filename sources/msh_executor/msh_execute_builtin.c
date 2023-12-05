/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   msh_execute_builtin.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haekang <haekang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 13:33:58 by jho               #+#    #+#             */
/*   Updated: 2023/12/05 19:34:03 by haekang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/msh.h"

int	msh_execute_builtin(int *fd, char **param, t_env *env, int forked)
{
	if (msh_strcmp(*param, "cd") == 0)
		return (msh_builtin_cd(fd, forked, param, env));
	else if (msh_strcmp(*param, "echo") == 0)
		return (msh_builtin_echo(fd, forked, param, env));
	else if (msh_strcmp(*param, "env") == 0)
		return (msh_builtin_env(fd, forked, param, env));
	else if (msh_strcmp(*param, "exit") == 0)
		return (msh_builtin_exit(fd, forked, param, env));
	else if (msh_strcmp(*param, "export") == 0)
		return (msh_builtin_export(fd, forked, param, env));
	else if (msh_strcmp(*param, "pwd") == 0)
		return (msh_builtin_pwd(fd, forked, param, env));
	else if (msh_strcmp(*param, "unset") == 0)
		return (msh_builtin_unset(fd, forked, param, env));
	return (0);
}
