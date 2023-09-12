/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   msh_tokenize_word.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jho <jho@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/29 20:50:05 by jho               #+#    #+#             */
/*   Updated: 2023/09/12 16:49:49 by jho              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int	msh_tokenize_word(t_token **tokens, char *str)
{
	int		end_idx;
	char	*value;
	t_token	*token;

	end_idx = 1;
	while (!msh_is_meta_char(*(str + end_idx)))
		++end_idx;
	value = msh_substr(str, 0, end_idx);
	if (value == 0)
		return (-1);
	token = malloc(sizeof(t_token));
	if (token == 0)
	{
		free(value);
		return (-1);
	}
	token->value = value;
	if (msh_count_equal_sign(value) == 0)
		token->symbol = WORD;
	else if (msh_count_equal_sign(value) == 1)
		token->symbol = ASSIGNMENT_WORD;
	else
		return (-1);
	token->next = 0;
	msh_append_token(tokens, token);
	return (end_idx);
}
