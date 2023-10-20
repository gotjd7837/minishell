/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   msh_tokenize_equal_sign.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haekang <haekang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/12 16:54:10 by jho               #+#    #+#             */
/*   Updated: 2023/10/20 15:15:37 by haekang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/minishell.h"

int	msh_tokenize_equal_sign(t_token **tokens, char *str)
{
	t_token	*token;
	char	*value;

	value = msh_substr(str, 0, 1);
	if (value == 0)
		return (-1);
	token = malloc(sizeof(t_token));
	if (token == 0)
	{
		free(value);
		return (-1);
	}
	token->symbol = EQUAL_SIGN;
	token->value = value;
	token->next = 0;
	msh_append_token(tokens, token);
	return (msh_strlen(value));
}
