/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   msh_parse_redir_list.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jho <jho@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 21:57:38 by jho               #+#    #+#             */
/*   Updated: 2023/10/30 22:02:13 by jho              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/msh_parser.h"

int	msh_parse_redir_list(t_token **parse_tree, t_token **sym_table)
{
	t_token	*parent;
	t_token	*child;

	parent = msh_token_malloc_sym(REDIR_LIST);
	if (parent == NULL)
		return (0);
	msh_token_add_child(parse_tree, parent);
	while (msh_accept(*sym_table, REDIR))
	{
		child = msh_token_dequeue(sym_table);
		if (child == NULL)
			return (0);
		child->next = NULL;
		msh_token_add_child(&parent, child);
	}
	return (1);
}
