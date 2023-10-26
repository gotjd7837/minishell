/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   msh_token_add_next.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jho <jho@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 09:11:22 by jho               #+#    #+#             */
/*   Updated: 2023/10/26 14:53:37 by jho              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/msh_token.h"

void	msh_token_add_next(t_token **head, t_token *token)
{
	t_token	*last;

	if (head == NULL || token == NULL)
		return ;
	if (*head == NULL)
		*head = token;
	else
	{
		last = msh_token_last(*head);
		last->next = token;
	}
}
