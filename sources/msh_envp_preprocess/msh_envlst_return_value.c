/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   msh_envlst_return_value.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haekang <haekang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 17:47:35 by haekang           #+#    #+#             */
/*   Updated: 2023/10/10 18:27:56 by haekang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

char	*msh_envlst_return_value(t_env *envp_list, char *key)
{
	t_env	*node;

	node = envp_list;
	while (1)
	{
		if (node->next == NULL)
		{
			if (msh_strcmp(node->key, key) == 0)
				return (node->value);
			break ;
		}
		else
		{
			if (msh_strcmp(node->key, key) == 0)
				return (node->value);
		}
		node = node->next;
	}
	return (NULL);
}

//key값 넣으면 return value, key가 없으면 NULL반환