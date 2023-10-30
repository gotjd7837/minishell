/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   msh_parse_pipeline.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jho <jho@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 21:58:43 by jho               #+#    #+#             */
/*   Updated: 2023/10/30 21:58:57 by jho              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/msh_parser.h"

int	msh_parse_pipeline(t_token **parse_tree, t_token **sym_table)
{
	t_token	*parent;
	t_token	*child;

	parent = msh_token_malloc_sym(PIPELINE);
	if (parent == NULL)
		return (0);
	msh_token_add_child(parse_tree, parent);
	if (!msh_parse_cmd(&parent, sym_table))
		return (0);
	if (msh_accept(*sym_table, PIPE))
	{
		child = msh_token_dequeue(sym_table);
		if (child == NULL)
			return (0);
		child->next = NULL;
		msh_token_add_child(&parent, child);
		if (!msh_parse_pipeline(&parent, sym_table))
			return (0);
	}
	return (1);
}
