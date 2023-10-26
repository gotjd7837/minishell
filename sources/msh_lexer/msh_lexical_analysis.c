/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   msh_lexical_analysis.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haekang <haekang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 10:40:49 by jho               #+#    #+#             */
/*   Updated: 2023/10/20 17:20:44 by haekang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

static int	msh_tokenizer(t_token **tokens, char *input)
{
	int		token_len;
	int		idx;

	*tokens = NULL;
	idx = 0;
	while (*(input + idx) != '\0')
	{
		token_len = msh_input_tokenize(tokens, input + idx);
		if (token_len == -1)
			return (-1);
		idx += token_len;
	}
	return (0);
}

t_token	*msh_lexical_analysis(char *input, t_env *env)
{
	t_token	*tokens;
	char	*expanded;

	expanded = msh_expand_input(input, env);
	if (expanded == NULL)
	{
		printf("Error\n");
		return (NULL);
	}
	if (msh_tokenizer(&tokens, expanded) == -1)
	{
		printf("tokenizer error\n");
		free(expanded);
		return ((t_token *)msh_free_tokens(tokens));
	}
	free(expanded);
	return (tokens);
}
