/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   msh_token_add_next.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haekang <haekang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 09:11:22 by jho               #+#    #+#             */
/*   Updated: 2023/12/05 19:38:07 by haekang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/msh.h"

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
