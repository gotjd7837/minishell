/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   msh_token_malloc_symval.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jho <jho@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 09:09:40 by jho               #+#    #+#             */
/*   Updated: 2023/10/26 09:09:47 by jho              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "msh_token.h"

t_token	*msh_token_malloc_symval(t_symbol sym, char *val)
{
	t_token	*token;

	token = malloc(sizeof(t_token));
	if (token == NULL)
		return (NULL);
	token->sym = sym;
	token->val = val;
	token->next = NULL;
	token->child = NULL;
	return (token);
}
