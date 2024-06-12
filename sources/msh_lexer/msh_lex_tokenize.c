/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   msh_lex_tokenize.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haeseong <haeseong@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/28 08:50:31 by jho               #+#    #+#             */
/*   Updated: 2024/06/12 18:54:56 by haeseong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/msh.h"

int	msh_lex_tokenize(t_token **sym_table, char *s)
{
	if (msh_is_whitespace(*s))
		return (1);
	// 리다이렉션 토큰화 함수 호출
	else if (*s == '<' || *s == '>')
		return (msh_lex_tokenize_redir(sym_table, s));
	// quote 토큰화 함수 호출
	else if (*s == '\"' || *s == '\'')
		return (msh_lex_tokenize_qoutes(sym_table, s));
	else
		return (msh_lex_tokenize_word(sym_table, s));
}
