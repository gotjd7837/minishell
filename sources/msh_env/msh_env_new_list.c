/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   msh_env_new_list.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haekang <haekang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/12 13:42:27 by jho               #+#    #+#             */
/*   Updated: 2023/12/05 19:33:44 by haekang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/msh.h"

t_env	*msh_env_new_list(char *envp[])
{
	int		index;
	t_env	*env;

	index = 0;
	env = NULL;
	while (*(envp + index) != NULL)
	{
		if (!msh_env_add_node(&env, *(envp + index)))
			return (msh_env_free_list(env));
		++index;
	}
	return (env);
}
