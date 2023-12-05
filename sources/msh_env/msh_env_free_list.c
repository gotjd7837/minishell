/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   msh_env_free_list.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haekang <haekang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/12 16:10:43 by jho               #+#    #+#             */
/*   Updated: 2023/12/05 19:33:28 by haekang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/msh.h"

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
