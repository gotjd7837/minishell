/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   msh_parse.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jho <jho@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 12:17:25 by jho               #+#    #+#             */
/*   Updated: 2023/10/24 16:41:45 by jho              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

t_token	*msh_parse(t_token **tokens)
{
	t_token	*root;
	t_token	*node;

	root = msh_new_token_by_sym(ROOT);
	while (*tokens != NULL)
	{
		if (msh_accept(WORD, *tokens) || msh_accept(ASSIGNMENT_WORD, *tokens)
				|| msh_accept(REDIRECTION, *tokens))
		{
			node = msh_new_token_by_sym(LIST);
			msh_add_child(root, node);
			if (msh_parse_list(node, tokens) == 0)
				return (NULL);
		}
		else if (msh_accept(L_BRACKET, *tokens))
		{
			node = msh_new_token_by_sym(SUBSHELL);
			msh_add_child(root, node);
			if (msh_parse_subshell(node, tokens) == 0)
				return (NULL);
		}
		else
			return (NULL);
	}
	return (root);
}
