/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   msh_token_add_child.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jho <jho@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 09:14:41 by jho               #+#    #+#             */
/*   Updated: 2023/10/26 09:16:28 by jho              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "msh_token.h"

void	msh_token_add_child(t_token *parent, t_token *child)
{
	if (parent == NULL || child == NULL)
		return ;
	if (parent->child == NULL)
		parent->child = child;
	else
		(msh_token_last(parent->child))->next = child;
}
