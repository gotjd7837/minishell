/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   msh_env_last_node.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haekang <haekang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/12 16:09:44 by jho               #+#    #+#             */
/*   Updated: 2023/12/05 19:33:41 by haekang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/msh.h"

t_env	*msh_env_last_node(t_env *list)
{
	if (list == NULL)
		return (NULL);
	while (list->next != NULL)
		list = list->next;
	return (list);
}
