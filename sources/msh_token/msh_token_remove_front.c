/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   msh_token_remove_front.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jho <jho@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 17:29:23 by jho               #+#    #+#             */
/*   Updated: 2023/10/30 17:31:12 by jho              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/msh_token.h"

void	msh_token_remove_front(t_token **tokens)
{
	t_token	*next;

	if (tokens == NULL || *tokens == NULL)
		return ;
	next = (*tokens)->next;
	free(*tokens);
	*tokens = next;
}
