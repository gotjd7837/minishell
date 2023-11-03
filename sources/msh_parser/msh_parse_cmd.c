/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   msh_parse_cmd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jho <jho@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 21:58:13 by jho               #+#    #+#             */
/*   Updated: 2023/10/30 21:58:31 by jho              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/msh_parser.h"

int	msh_parse_cmd(t_token **parse_tree, t_token **sym_table)
{
	t_token	*parent;

	parent = msh_token_malloc_sym(CMD);
	if (parent == NULL)
		return (0);
	msh_token_add_child(parse_tree, parent);
	if (msh_accept(*sym_table, WORD) || msh_accept(*sym_table, ASSIGN_WORD)
		|| msh_accept(*sym_table, REDIR))
	{
		if (!msh_parse_simple_cmd(&parent, sym_table))
			return (0);
	}
	else if (msh_accept(*sym_table, L_BRA))
	{
		if (!msh_parse_subshell(&parent, sym_table))
			return (0);
		if (msh_accept(*sym_table, REDIR)
			&& !msh_parse_redir_list(&parent, sym_table))
			return (0);
	}
	else
		return (0);
	return (1);
}
