/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   msh_lex_tokenize_redir.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haekang <haekang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/28 08:49:22 by jho               #+#    #+#             */
/*   Updated: 2023/12/05 19:36:18 by haekang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/msh.h"

int	msh_lex_tokenize_redir(t_token **sym_table, char *s)
{
	int		idx;
	t_token	*token;

	idx = 1;
	if (*(s + 1) == '<' || *(s + 1) == '>')
		idx = 2;
	while (msh_is_whitespace(*(s + idx)) && *(s + idx) != '\0')
		++idx;
	if (msh_is_charset(*(s + idx), "|&<>()") || *(s + idx) == '\0')
		return (0);
	while (!msh_is_charset(*(s + idx), "|&<>()") && *(s + idx) != '\0'
		&& !msh_is_whitespace(*(s + idx)))
		++idx;
	token = msh_token_malloc_sym(REDIR);
	if (token == NULL)
		return (0);
	token->val = msh_substr(s, 0, idx);
	if (token->val == NULL)
	{
		msh_token_free(token);
		return (0);
	}
	msh_token_add_next(sym_table, token);
	return (idx);
}
