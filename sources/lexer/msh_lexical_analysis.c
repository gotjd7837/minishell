/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   msh_lexical_analysis.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jho <jho@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/29 15:14:26 by jho               #+#    #+#             */
/*   Updated: 2023/08/29 21:04:53 by jho              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

t_token	*msh_lexical_analysis(char *input)
{
	t_token	*tokens;
	int		token_len;
	int		idx;

	tokens = 0;
	idx = 0;
	while (*(input + idx) != '\0')
	{
		token_len = msh_tokenize(&tokens, input + idx);
		if (token_len == -1)
		{
			write(2, "Malloc failed.\n", 15);
			return (msh_free_tokens(tokens));
		}
		idx += token_len;
	}
	return (tokens);
}
