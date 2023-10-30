/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   msh_parse_subshell.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jho <jho@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 21:57:12 by jho               #+#    #+#             */
/*   Updated: 2023/10/30 22:01:59 by jho              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/msh_parser.h"

int	msh_parse_subshell(t_token **parse_tree, t_token **sym_table)
{
	t_token	*parent;

	parent = msh_token_malloc_sym(SUBSHELL);
	if (parent == NULL)
		return (0);
	msh_token_add_child(parse_tree, parent);
	if (msh_accept(*sym_table, L_BRA))
		msh_token_remove_front(sym_table);
	else
		return (0);
	if (!msh_parse_list(&parent, sym_table))
		return (0);
	if (msh_accept(*sym_table, R_BRA))
		msh_token_remove_front(sym_table);
	else
		return (0);
	return (1);
}
