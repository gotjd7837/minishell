/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   msh_parse_simple_cmd.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jho <jho@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 21:56:44 by jho               #+#    #+#             */
/*   Updated: 2023/10/30 21:56:57 by jho              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/msh_parser.h"

int	msh_parse_simple_cmd(t_token **parse_tree, t_token **sym_table)
{
	t_token	*parent;
	t_token	*child;

	parent = msh_token_malloc_sym(SIMPLE_CMD);
	if (parent == NULL)
		return (0);
	msh_token_add_child(parse_tree, parent);
	while (msh_accept(*sym_table, WORD) || msh_accept(*sym_table, ASSIGN_WORD)
		|| msh_accept(*sym_table, REDIR))
	{
		child = msh_token_dequeue(sym_table);
		if (child == NULL)
			return (0);
		child->next = NULL;
		msh_token_add_child(&parent, child);
	}
	return (1);
}
