/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   msh_env_add_node.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jho <jho@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/12 16:10:17 by jho               #+#    #+#             */
/*   Updated: 2023/10/17 11:47:56 by jho              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int	msh_env_add_node(t_env **list, char *envp)
{
	t_env	*node;
	t_env	*last;

	if (list == NULL || !msh_strchr(envp, '='))
		return (0);
	if (!msh_env_new_node(&node))
		return (0);
	node->key = msh_env_parse_key(envp);
	node->value = msh_env_parse_value(envp);
	if (node->key == NULL || node->value == NULL)
		return ((int)msh_env_free_node(node));
	if (*list == NULL)
		*list = node;
	else
	{
		last = msh_env_last_node(*list);
		last->next = node;
		node->prev = last;
	}
	return (1);
}
