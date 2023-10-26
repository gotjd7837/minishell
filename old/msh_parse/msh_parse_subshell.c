/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   msh_parse_subshell.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jho <jho@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 15:54:54 by jho               #+#    #+#             */
/*   Updated: 2023/10/24 16:55:51 by jho              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int	msh_parse_subshell(t_token *root, t_token **tokens)
{
	t_token	*token;

	if (!msh_accept(L_BRACKET, *tokens))
		return (0);
	token = msh_dequeue(tokens);
	msh_add_child(root, token);
	token = msh_new_token_by_sym(LIST);
	msh_add_child(root, token);
	if (msh_parse_list(token, tokens) == 0)
		return (0);
	if (!msh_accept(R_BRACKET, *tokens))
		return (0);
	token = msh_dequeue(tokens);
	msh_add_child(root, token);
	if (msh_accept(PIPE, *tokens))
	{
		token = msh_dequeue(tokens);
		msh_add_child(root, token);
		if (msh_parse_pipeline(token, tokens) == 0)
			return (0);
	}
	else if (msh_accept(AND_IF, *tokens) || msh_accept(OR_IF, *tokens))
	{
		token = msh_dequeue(tokens);
		msh_add_child(root, token);
		token = msh_new_token_by_sym(LIST);
		msh_add_child(root, token);
		if (msh_parse_list(token, tokens) == 0)
			return (0);
	}
	return (1);
}
