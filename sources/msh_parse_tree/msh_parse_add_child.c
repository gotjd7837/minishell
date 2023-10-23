/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   msh_parse_add_child.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haeseong <haeseong@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 21:15:11 by haeseong          #+#    #+#             */
/*   Updated: 2023/10/23 21:34:45 by haeseong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	msh_parse_add_child(t_tree *parent, t_tree *child)
{
	t_tree	*current;

	current = parent->children;
	if (current == NULL)
		current = child;
	else
	{
		while (current->children != NULL)
			current = current->children;
		current->children = child;
	}
}
