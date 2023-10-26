/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   msh_token_add_next.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jho <jho@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 09:11:22 by jho               #+#    #+#             */
/*   Updated: 2023/10/26 09:14:33 by jho              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "msh_token.h"

void	msh_token_add_next(t_token *head, t_token *token)
{
	if (head == NULL || token == NULL)
		return ;
	head = msh_token_last(head);
	head->next = token;
}
