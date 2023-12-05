/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   msh_builtin_export_create.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haekang <haekang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 18:12:33 by haekang           #+#    #+#             */
/*   Updated: 2023/12/05 19:52:45 by haekang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/msh.h"

static int	msh_export_add_only_key(t_env *env, char *cmd_arg)
{
	t_env	*node;
	t_env	*last_node;

	if (msh_export_key_exist(env, cmd_arg) == 1)
		return (0);
	else
	{
		if (!msh_env_new_node(&node))
			return (0);
		node->key = msh_strdup(cmd_arg);
		if (node->key == NULL)
			return (0);
		node->value = NULL;
		last_node = msh_env_last_node(env);
		last_node->next = node;
		node->prev = last_node;
	}
	return (1);
}

static int	msh_export_add_node(t_env *env, char *cmd_arg)
{
	t_env	*node;
	char	*key;

	key = msh_env_parse_key(cmd_arg);
	if (key == NULL)
		return (0);
	if (msh_export_key_exist(env, key))
	{
		node = msh_env_get_node(env, key);
		free(key);
		free(node->value);
		node->value = msh_env_parse_value(cmd_arg);
		if (node->value == NULL)
			return (0);
	}
	else
	{
		free(key);
		if (!msh_env_add_node(&env, cmd_arg))
			return (0);
	}
	return (1);
}

int	msh_export_create(char *cmd_arg, t_env *env)
{
	if (!msh_is_valid_identifier(cmd_arg))
		return (0);
	if (msh_strchr(cmd_arg, '='))
	{
		if (!msh_export_add_node(env, cmd_arg))
			return (0);
	}
	else
	{
		if (!msh_export_add_only_key(env, cmd_arg))
			return (0);
	}
	return (1);
}
