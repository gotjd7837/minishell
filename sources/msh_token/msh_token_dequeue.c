/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   msh_token_dequeue.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haekang <haekang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 17:09:29 by jho               #+#    #+#             */
/*   Updated: 2023/12/05 19:38:27 by haekang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/msh.h"

t_token	*msh_token_dequeue(t_token **tokens)
{
	t_token	*top_token;

	if (tokens == NULL || *tokens == NULL)
		return (0);
	top_token = *tokens;
	*tokens = (*tokens)->next;
	top_token->next = NULL;
	return (top_token);
}
