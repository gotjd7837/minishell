/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   msh_tokenize_amp.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jho <jho@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/29 20:46:18 by jho               #+#    #+#             */
/*   Updated: 2023/08/29 21:09:00 by jho              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int	msh_tokenize_amp(t_token **tokens, char *str)
{
	t_token	*token;
	char	*value;

	value = msh_substr(str, 0, 2);
	if (value == 0)
		return (-1);
	token = malloc(sizeof(t_token));
	if (token == 0)
	{
		free(value);
		return (-1);
	}
	token->symbol = AND_IF;
	token->value = value;
	token->next = 0;
	msh_append_token(tokens, token);
	return (msh_strlen(value));
}
