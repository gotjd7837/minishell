/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   msh_env_get_node.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jho <jho@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 08:23:29 by jho               #+#    #+#             */
/*   Updated: 2023/10/27 20:03:09 by jho              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/msh_env.h"

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
