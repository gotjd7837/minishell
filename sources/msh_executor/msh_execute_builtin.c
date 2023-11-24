/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   msh_execute_builtin.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jho <jho@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 13:33:58 by jho               #+#    #+#             */
/*   Updated: 2023/11/24 13:51:14 by jho              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/msh_executor.h"

int	msh_execute_builtin(int in, int out, char **param, t_env *env)
{
	if (msh_strcmp(*param, "cd") == 0)
		return (msh_builtin_cd(in, out, param, env));
	else if (msh_strcmp(*param, "echo") == 0)
		return (msh_builtin_echo(in, out, param, env));
	else if (msh_strcmp(*param, "env") == 0)
		return (msh_builtin_env(in, out, param, env));
	else if (msh_strcmp(*param, "exit") == 0)
		return (msh_builtin_exit(in, out, param, env));
	else if (msh_strcmp(*param, "export") == 0)
		return (msh_builtin_export(in, out, param, env));
	else if (msh_strcmp(*param, "pwd") == 0)
		return (msh_builtin_pwd(in, out, param, env));
	else if (msh_strcmp(*param, "unset") == 0)
		return (msh_builtin_unset(in, out, param, env));
	return (0);
}
