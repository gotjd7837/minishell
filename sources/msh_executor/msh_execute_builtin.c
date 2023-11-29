/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   msh_execute_builtin.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haekang <haekang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 13:33:58 by jho               #+#    #+#             */
/*   Updated: 2023/11/29 16:45:47 by jho              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/msh_executor.h"

int	msh_execute_builtin(int *fd, char **param, t_env *env, int forked)
{
	if (msh_strcmp(*param, "cd") == 0)
		return (msh_builtin_cd(fd, param, env, forked));
	else if (msh_strcmp(*param, "echo") == 0)
		return (msh_builtin_echo(fd, param, env, forked));
	else if (msh_strcmp(*param, "env") == 0)
		return (msh_builtin_env(fd, param, env, forked));
	else if (msh_strcmp(*param, "exit") == 0)
		return (msh_builtin_exit(fd, param, env, forked));
	else if (msh_strcmp(*param, "export") == 0)
		return (msh_builtin_export(fd, param, env, forked));
	else if (msh_strcmp(*param, "pwd") == 0)
		return (msh_builtin_pwd(fd, param, env, forked));
	else if (msh_strcmp(*param, "unset") == 0)
		return (msh_builtin_unset(fd, param, env, forked));
	return (0);
}
