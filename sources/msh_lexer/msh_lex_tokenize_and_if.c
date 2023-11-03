/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   msh_lex_tokenize_and_if.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jho <jho@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/28 08:46:44 by jho               #+#    #+#             */
/*   Updated: 2023/10/28 08:47:02 by jho              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/msh_lexer.h"

int	msh_lex_tokenize_and_if(t_token **sym_table, char *s)
{
	t_token	*token;

	token = msh_token_malloc_sym(AND_IF);
	if (token == NULL)
		return (0);
	token->val = msh_substr(s, 0, 2);
	if (token->val == NULL)
	{
		msh_token_free(token);
		return (0);
	}
	msh_token_add_next(sym_table, token);
	return (2);
}
