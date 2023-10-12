/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   msh_env_get_value.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jho <jho@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/12 18:29:48 by jho               #+#    #+#             */
/*   Updated: 2023/10/12 18:35:24 by jho              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

char	*msh_env_get_value(t_env *env, char *key)
{
	while (env != NULL)
	{
		if (msh_strcmp(key, env->key) == 0)
			return (env->value);
		env = env->next;
	}
	return (NULL);
}
