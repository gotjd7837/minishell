/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   msh_dequeue.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jho <jho@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 12:18:35 by jho               #+#    #+#             */
/*   Updated: 2023/10/24 16:48:38 by jho              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

t_token	*msh_dequeue(t_token **tokens)
{
	t_token	*token;

	if (tokens == NULL || *tokens == NULL)
		return (NULL);
	token = *tokens;
	*tokens = token->next;
	token->next = 0;
	token->child = 0;
	return (token);
}
