/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   msh_add_child.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jho <jho@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 12:37:43 by jho               #+#    #+#             */
/*   Updated: 2023/10/24 14:34:13 by jho              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	msh_add_child(t_token *tokens, t_token *child)
{
	t_token	*token;

	if (tokens == NULL || child == NULL)
		return ;
	if (tokens->child == NULL)
		tokens->child = child;
	else
	{
		token = tokens->child;
		while (token->next != NULL)
			token = token->next;
		token->next = child;
	}
}
