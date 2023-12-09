/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   msh_lex_tokenize_bra.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haekang <haekang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/28 08:48:09 by jho               #+#    #+#             */
/*   Updated: 2023/12/09 16:23:54 by haekang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/msh.h"

int	msh_lex_tokenize_bra(t_token **sym_table, char *s)
{
	t_token	*token;

	if (*s == '(')
		token = msh_token_malloc_sym(L_BRA);
	else
		token = msh_token_malloc_sym(R_BRA);
	if (token == NULL)
		return (0);
	token->val = msh_substr(s, 0, 1);
	if (token->val == NULL)
	{
		msh_token_free(token);
		return (0);
	}
	msh_token_add_next(sym_table, token);
	return (1);
}
