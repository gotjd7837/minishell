/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   msh_token_malloc.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jho <jho@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 09:09:15 by jho               #+#    #+#             */
/*   Updated: 2023/10/26 09:09:22 by jho              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "msh_token.h"

t_token	*msh_token_malloc(void)
{
	t_token	*token;

	token = malloc(sizeof(t_token));
	if (token == NULL)
		return (NULL);
	token->sym = 0;
	token->val = NULL;
	token->next = NULL;
	token->child = NULL;
	return (token);
}
