/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   msh_create_parse_tree.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haeseong <haeseong@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 19:21:56 by haeseong          #+#    #+#             */
/*   Updated: 2023/10/24 04:21:46 by haeseong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

t_tree	*msh_create_parse_tree(t_token **tokens)
{
	t_tree	*root;
	t_tree	*node;

	if (*tokens == NULL)
		return (NULL);
	root = msh_parse_new_node(ROOT);
	if (root == NULL)
		return (NULL);
	if (msh_accept(tokens, WORD) || msh_accept(tokens, REDIRECTION)
		|| msh_accept(tokens, ASSIGNMENT_WORD))
	{
		node = msh_parse_new_node(LIST);
		if (node == NULL)
			return (NULL);
		msh_parse_add_child(root, node);
		if (!msh_parse_list(tokens, node))
			return (NULL);//트리 프리해주기
	}
	else if (msh_accept(tokens, L_BRACKET))
	{
		node = msh_parse_new_node(COMMAND);
		if (node == NULL)
			return (NULL);
		msh_parse_add_child(root, node);
		if (!msh_parse_command(tokens, node))
			return (NULL);//트리 프리
	}
	else
		//error
	return (root);
}
