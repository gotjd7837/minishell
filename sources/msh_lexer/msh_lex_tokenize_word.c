/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   msh_lex_tokenize_word.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haekang <haekang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/28 08:50:12 by jho               #+#    #+#             */
/*   Updated: 2023/12/05 16:23:51 by jho              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/msh_lexer.h"
#include "../../includes/msh_expander.h"

int	msh_lex_tokenize_word_qoutes_find_last_idx(char *s)
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

char	*msh_lex_tokenize_word_clear_qoutes(char *s)
{
	t_token	*tokens;

	tokens = msh_vqoutes(s);
	if (!msh_trim_both_end(&tokens))
		return (NULL);
	free(s);
	s = msh_token_union_val(tokens);
	msh_token_free_list(tokens);
	return (s);
}

int	msh_lex_tokenize_word(t_token **sym_table, char *s)
{
	int		idx;
	t_token	*token;

	idx = msh_lex_tokenize_word_qoutes_find_last_idx(s);
	token = msh_token_malloc_sym(WORD);
	if (token == NULL)
		return (0);
	token->val = msh_substr(s, 0, idx);
	token->val = msh_lex_tokenize_word_clear_qoutes(token->val);
	if (token->val == NULL)
	{
		msh_token_free(token);
		return (0);
	}
	msh_token_add_next(sym_table, token);
	return (idx);
}
