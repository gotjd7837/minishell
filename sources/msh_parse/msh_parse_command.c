/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   msh_parse_command.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jho <jho@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 13:00:53 by jho               #+#    #+#             */
/*   Updated: 2023/10/24 16:08:14 by jho              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int	msh_parse_command(t_token *root, t_token **tokens)
{
	t_token	*token;

	if (msh_accept(L_BRACKET, *tokens))
	{
		token = msh_new_token_by_sym(SUBSHELL);
		msh_add_child(root, token);
		if (msh_parse_subshell(token, tokens) == 0)
			return (0);
		if (msh_accept(REDIRECTION, *tokens))
		{
			token = msh_new_token_by_sym(REDIRECTION_LIST);
			msh_add_child(root, token);
			if (msh_parse_redirection_list(token, tokens) == 0)
				return (0);
		}
	}
	else
	{
		token = msh_new_token_by_sym(SIMPLE_COMMAND);
		msh_add_child(root, token);
		msh_parse_simple_command(token, tokens);
	}
	return (1);
}
