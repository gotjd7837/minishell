/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   msh_token_free_list.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jho <jho@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 08:54:21 by jho               #+#    #+#             */
/*   Updated: 2023/10/26 09:02:05 by jho              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "msh_token.h"

void	msh_token_free_list(t_token *token)
{
	t_token	*next;

	if (token == NULL)
		return ;
	while (token != NULL)
	{
		next = token->next;
		msh_token_free(token);
		token = next;
	}
}
