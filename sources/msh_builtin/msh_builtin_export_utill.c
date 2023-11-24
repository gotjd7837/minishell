/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   msh_builtin_export_utill.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haekang <haekang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 18:22:20 by haekang           #+#    #+#             */
/*   Updated: 2023/11/25 01:06:39 by haekang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/msh_builtin.h"

int	msh_export_key_exist(t_env *env, char *key)
{
	while (env != NULL)
	{
		if (!msh_strcmp(key, env->key))
			return (1);
		env = env->next;
	}
	return (0);
}

int	msh_check_key(char *cmd_arg)
{
	int	i;

	i = 0;
	while (cmd_arg[i] != '=' && cmd_arg[i] != '\0')
	{
		if ((cmd_arg[i] >= 'a' && cmd_arg[i] <= 'z')
			|| (cmd_arg[i] >= 'A' && cmd_arg[i] <= 'Z')
			|| (cmd_arg[i] >= '0' && cmd_arg[i] <= '9')
			|| (cmd_arg[i] == '_'))
			i++;
		else
		{
			printf("minishell: export: `%s': not a valid identifier\n", cmd_arg);
			g_exit_status = 1;
			return (0);
		}
	}
	return (1);
}

int	msh_is_valid_identifier(char *cmd_arg)
{
	int	i;

	i = 0;
	if ((cmd_arg[0] >= 'a' && cmd_arg[0] <= 'z')
		|| (cmd_arg[0] >= 'A' && cmd_arg[0] <= 'Z') || (cmd_arg[0] == '_'))
	{
		if (!msh_check_key(cmd_arg))
			return (0);
		return (1);
	}
	else
	{
		printf("minishell: export: `%s': not a valid identifier\n", cmd_arg);
		g_exit_status = 1;
		return (0);
	}
}
