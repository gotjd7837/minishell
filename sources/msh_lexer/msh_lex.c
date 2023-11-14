/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   msh_lex.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haekang <haekang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/27 21:32:25 by jho               #+#    #+#             */
/*   Updated: 2023/11/14 20:32:45 by haekang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/msh_lexer.h"

t_token	*msh_lex(char *s)
{
	int			idx;
	int			token_len;
	t_token		*sym_table;
	// t_pipeline	*pipelines;

	idx = 0;
	sym_table = NULL;
	while (*(s + idx) != '\0')
	{
		token_len = msh_lex_tokenize(&sym_table, s + idx);
		if (token_len == 0)
			return (msh_token_free_list(sym_table));
		idx += token_len;
	}
	// pipelines = msh_divide_pipeline(&sym_table);
	// return (pipelines);
	return (sym_table);
}
