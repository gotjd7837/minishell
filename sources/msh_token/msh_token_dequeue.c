/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   msh_token_dequeue.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jho <jho@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 17:09:29 by jho               #+#    #+#             */
/*   Updated: 2023/10/30 18:16:44 by jho              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/msh_token.h"

t_token	*msh_token_dequeue(t_token **tokens)
{
	t_token	*top_token;

	if (tokens == NULL || *tokens == NULL)
		return (0);
	top_token = *tokens;
	*tokens = (*tokens)->next;
	return (top_token);
}
