/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   msh_builtin_export_util.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haekang <haekang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 18:22:20 by haekang           #+#    #+#             */
/*   Updated: 2023/12/06 16:19:56 by haekang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/msh.h"

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
			write(2, "minishell: export: `", 20);
			write(2, cmd_arg, msh_strlen(cmd_arg));
			write(2, "': not a valid identifier\n", 26);
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
		write(2, "minishell: export: `", 20);
		write(2, cmd_arg, msh_strlen(cmd_arg));
		write(2, "': not a valid identifier\n", 26);
		return (0);
	}
}
