/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   msh_parse.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jho <jho@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 16:40:09 by jho               #+#    #+#             */
/*   Updated: 2023/10/30 21:59:29 by jho              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/msh_parser.h"

t_token	*msh_parse(t_token **sym_table)
{
	t_token	*parse_tree;

	parse_tree = msh_token_malloc_sym(ROOT);
	if (parse_tree == NULL)
		return (NULL);
	while (msh_accept(*sym_table, WORD) || msh_accept(*sym_table, ASSIGN_WORD)
		|| msh_accept(*sym_table, REDIR) || msh_accept(*sym_table, L_BRA))
	{
		if (!msh_parse_list(&parse_tree, sym_table))
			return (msh_token_free_tree(parse_tree));
	}
	if (*sym_table == NULL)
		return (parse_tree);
	return (NULL);
}
