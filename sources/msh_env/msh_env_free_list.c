/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   msh_env_free_list.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jho <jho@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/12 16:10:43 by jho               #+#    #+#             */
/*   Updated: 2023/10/17 11:49:46 by jho              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

t_env	*msh_env_free_list(t_env *list)
{
	t_env	*node;
	t_env	*next;

	node = NULL;
	next = NULL;
	if (list == NULL)
		return (NULL);
	node = list;
	while (next != NULL)
	{
		next = node->next;
		msh_env_free_node(node);
	}
	return (NULL);
}
