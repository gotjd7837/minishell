/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   msh_parse_simple_command.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jho <jho@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 13:03:14 by jho               #+#    #+#             */
/*   Updated: 2023/10/24 14:32:03 by jho              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int	msh_parse_simple_command(t_token *root, t_token **tokens)
{
	t_token	*token;

	token = msh_new_token_by_sym(SIMPLE_COMMAND_ELEMENT);
	msh_add_child(root, token);
	msh_parse_simple_command_element(token, tokens);
	while (msh_accept(WORD, *tokens) || msh_accept(ASSIGNMENT_WORD, *tokens)
			|| msh_accept(REDIRECTION, *tokens))
	{
		token = msh_new_token_by_sym(SIMPLE_COMMAND_ELEMENT);
		msh_add_child(root, token);
		msh_parse_simple_command_element(token, tokens);
	}
	return (1);
}
