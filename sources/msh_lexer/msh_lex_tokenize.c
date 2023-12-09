/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   msh_lex_tokenize.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haekang <haekang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/28 08:50:31 by jho               #+#    #+#             */
/*   Updated: 2023/12/09 16:26:32 by jho              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/msh.h"

int	msh_lex_tokenize(t_token **sym_table, char *s)
{
	if (msh_is_whitespace(*s))
		return (1);
	else if (*s == '<' || *s == '>')
		return (msh_lex_tokenize_redir(sym_table, s));
	else if (*s == '\"' || *s == '\'')
		return (msh_lex_tokenize_qoutes(sym_table, s));
	else
		return (msh_lex_tokenize_word(sym_table, s));
}
