/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   msh_parse_new_node.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haeseong <haeseong@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 19:45:46 by haeseong          #+#    #+#             */
/*   Updated: 2023/10/23 20:41:17 by haeseong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

t_tree	*msh_parse_new_node(t_symbol symbol)
{
	t_tree	*node;

	node = malloc(sizeof(t_tree));
	if (node == NULL)
	{
		printf("malloc error\n");
		return (NULL);
	}
	node->symbol = symbol;
	node->children = NULL;
	node->value = NULL;
	return (node);
}
