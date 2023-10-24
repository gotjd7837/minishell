/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   msh_parse.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jho <jho@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 12:17:25 by jho               #+#    #+#             */
/*   Updated: 2023/10/24 14:26:21 by jho              ###   ########.fr       */
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
		if (msh_accept(WORD, *tokens) || msh_accept(REDIRECTION, *tokens))
		{
			node = msh_new_token_by_sym(LIST);
			msh_add_child(root, node);
			msh_parse_list(node, tokens);
		}
	}
	return (root);
}
