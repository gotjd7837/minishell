/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   msh_env_new_node.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haekang <haekang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/12 16:08:26 by jho               #+#    #+#             */
/*   Updated: 2023/12/05 19:33:47 by haekang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/msh.h"

int	msh_env_new_node(t_env **node)
{
	*node = malloc(sizeof(t_env));
	if (*node == NULL)
		return (0);
	(*node)->key = NULL;
	(*node)->value = NULL;
	(*node)->prev = NULL;
	(*node)->next = NULL;
	return (1);
}
