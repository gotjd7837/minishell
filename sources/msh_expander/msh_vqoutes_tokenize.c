/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   msh_vqoutes_tokenize.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haekang <haekang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 15:38:44 by jho               #+#    #+#             */
/*   Updated: 2023/11/14 14:04:44 by haekang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/msh_expander.h"

t_token	*msh_vqoutes_tokenize(char *s, int *idx, int num)
{
	int		csr;
	t_token	*tokens;

	csr = -1;
	tokens = NULL;
	if (num == 0)
		return (msh_token_add_substr(&tokens, s, 0, msh_strlen(s)));
	if ((idx[0] != 0) && !msh_token_add_substr(&tokens, s, 0, idx[0]))
		return (msh_token_free_list(tokens));
	while (++csr < num - 1)
	{
		if ((csr % 2 == 0)
			&& !msh_token_add_substr(&tokens, s, idx[csr], idx[csr + 1] + 1))
			return (msh_token_free_list(tokens));
		if ((csr % 2 == 1) && (idx[csr] + 1 != idx[csr + 1])
			&& !msh_token_add_substr(&tokens, s, idx[csr] + 1, idx[csr + 1]))
			return (msh_token_free_list(tokens));
	}
	if (idx[csr] + 1 != msh_strlen(s)
		&& !msh_token_add_substr(&tokens, s, idx[csr] + 1, msh_strlen(s) + 1))
		return (msh_token_free_list(tokens));
	return (tokens);
}
