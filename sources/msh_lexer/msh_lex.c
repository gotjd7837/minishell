/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   msh_lex.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jho <jho@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/27 21:32:25 by jho               #+#    #+#             */
/*   Updated: 2023/10/28 08:50:51 by jho              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/msh_lexer.h"

t_token	*msh_lex(char *s)
{
	int		idx;
	int		token_len;
	t_token	*sym_table;

	idx = 0;
	sym_table = NULL;
	while (*(s + idx) != '\0')
	{
		token_len = msh_lex_tokenize(&sym_table, s + idx);
		if (token_len == 0)
			return (msh_token_free_list(sym_table));
		idx += token_len;
	}
	return (sym_table);
}
