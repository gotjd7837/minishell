/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   msh_token_remove_front.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haekang <haekang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 17:29:23 by jho               #+#    #+#             */
/*   Updated: 2023/12/05 19:39:16 by haekang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/msh.h"

void	msh_token_remove_front(t_token **tokens)
{
	t_token	*next;

	if (tokens == NULL || *tokens == NULL)
		return ;
	next = (*tokens)->next;
	msh_token_free(*tokens);
	*tokens = next;
}
