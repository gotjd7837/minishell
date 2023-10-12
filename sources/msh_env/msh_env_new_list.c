/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   msh_env_new_list.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jho <jho@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/12 13:42:27 by jho               #+#    #+#             */
/*   Updated: 2023/10/12 16:11:06 by jho              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

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
