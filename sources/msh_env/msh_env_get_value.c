/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   msh_env_get_value.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haekang <haekang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/12 18:29:48 by jho               #+#    #+#             */
/*   Updated: 2023/12/05 19:33:38 by haekang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/msh.h"

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
	return (msh_strdup("\0"));
}
