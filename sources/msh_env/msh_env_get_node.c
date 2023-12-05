/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   msh_env_get_node.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haekang <haekang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 08:23:29 by jho               #+#    #+#             */
/*   Updated: 2023/12/05 19:33:34 by haekang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/msh.h"

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
