/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   msh_lex_tokenize.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haekang <haekang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/28 08:50:31 by jho               #+#    #+#             */
/*   Updated: 2023/11/23 15:34:16 by haekang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/msh_lexer.h"

int	msh_lex_tokenize(t_token **sym_table, char *s)
{
	if (*s == '&' && *(s + 1) == '&')
		return (msh_lex_tokenize_and_if(sym_table, s));
	// else if (*s == '|' && *(s + 1) == '|')
	// 	return (msh_lex_tokenize_or_if(sym_table, s));
	// else if (*s == '|')
	// 	return (msh_lex_tokenize_pipe(sym_table, s));
	else if (*s == '(' || *s == ')')
		return (msh_lex_tokenize_bra(sym_table, s));
	else if (msh_is_whitespace(*s))
		return (1);
	else if (*s == '<' || *s == '>')
		return (msh_lex_tokenize_redir(sym_table, s));
	else if (*s == '\"' || *s == '\'')
		return (msh_lex_tokenize_qoutes(sym_table, s));
	else
		return (msh_lex_tokenize_word(sym_table, s));
}
