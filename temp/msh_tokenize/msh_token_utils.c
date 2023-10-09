/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   msh_tokens.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jho <jho@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/29 20:29:02 by jho               #+#    #+#             */
/*   Updated: 2023/08/29 20:30:08 by jho              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int	msh_append_token(t_token **tokens, t_token *token)
{
	t_token	*last;

	if (*tokens == 0)
		*tokens = token;
	else
	{
		last = *tokens;
		while (last->next != 0)
			last = last->next;
		last->next = token;
	}
	return (0);
}

t_token	*msh_free_tokens(t_token *tokens)
{
	t_token	*node;
	t_token	*next;

	if (tokens == 0)
		return (0);
	node = tokens;
	while (node != 0)
	{
		next = node->next;
		free(node);
		node = next;
	}
	return (0);
}
