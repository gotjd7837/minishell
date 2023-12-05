/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   msh_lex_tokenize_qoutes.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haekang <haekang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/28 08:49:45 by jho               #+#    #+#             */
/*   Updated: 2023/12/05 10:54:20 by jho              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/msh_lexer.h"

int	msh_lex_tokenize_qoutes_find_last_idx(char *s)
{
	int	qoute_idx;
	int	last_idx;

	qoute_idx = 0;
	last_idx = 0;
	while (!msh_is_charset(*(s + last_idx), "|<> ") && *(s + last_idx) != '\0')
	{
		if (msh_is_charset(*(s + last_idx), "\'\""))
		{
			qoute_idx = last_idx++;
			while (*(s + last_idx) != *(s + qoute_idx))
				++last_idx;
		}
		++last_idx;
	}
	return (last_idx);
}

int	msh_lex_tokenize_qoutes(t_token **sym_table, char *s)
{
	int		last_idx;
	t_token	*token;

	last_idx = msh_lex_tokenize_qoutes_find_last_idx(s);
	token = msh_token_malloc_sym(WORD);
	if (token == NULL)
		return (0);
	token->val = msh_substr(s, 1,
			last_idx - msh_is_charset(*(s + last_idx - 1), "\'\""));
	if (token->val == NULL)
	{
		msh_token_free(token);
		return (0);
	}
	msh_token_add_next(sym_table, token);
	return (last_idx);
}
