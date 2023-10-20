/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   msh_env_get_value.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haekang <haekang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/12 18:29:48 by jho               #+#    #+#             */
/*   Updated: 2023/10/20 14:05:12 by haekang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

char	*msh_env_get_value(t_env *env, char *key)
{
	char	*value;

	value = NULL;
	while (env != NULL)
	{
		if (!msh_strcmp(key, env->key))
		{
			value = msh_strdup(env->value);
			return (value);
		}
		env = env->next;
	}
	return (value);
}

t_env	*msh_env_get_node(t_env *env, char *key)
{
	while (env != NULL)
	{
		if (msh_strcmp(key, env->key) == 0)
			return (env);
		env = env->next;
	}
	return (NULL);
}
