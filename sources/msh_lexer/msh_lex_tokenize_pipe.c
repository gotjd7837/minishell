/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   msh_lex_tokenize_pipe.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haekang <haekang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/28 08:47:43 by jho               #+#    #+#             */
/*   Updated: 2023/12/05 19:42:46 by haekang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/msh.h"

int	msh_lex_tokenize_pipe(t_token **sym_table, char *s)
{
	t_token	*token;

	token = msh_token_malloc_sym(PIPE);
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
