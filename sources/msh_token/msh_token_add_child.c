/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   msh_token_add_child.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jho <jho@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 09:14:41 by jho               #+#    #+#             */
/*   Updated: 2023/10/31 00:13:53 by jho              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/msh_token.h"

void	msh_token_add_child(t_token **parent, t_token *child)
{
	t_token	*parent_cpy;

	if (parent == NULL || *parent == NULL || child == NULL)
		return ;
	parent_cpy = *parent;
	if (parent_cpy->child == NULL)
		parent_cpy->child = child;
	else
	{
		parent_cpy = parent_cpy->child;
		while (parent_cpy->next != NULL)
			parent_cpy = parent_cpy->next;
		parent_cpy->next = child;
	}
}
