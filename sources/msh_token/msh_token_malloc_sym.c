/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   msh_token_malloc_sym.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haekang <haekang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 09:09:29 by jho               #+#    #+#             */
/*   Updated: 2023/12/05 19:38:53 by haekang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/msh.h"

t_token	*msh_token_malloc_sym(t_sym sym)
{
	t_token	*token;

	token = malloc(sizeof(t_token));
	if (token == NULL)
		return (NULL);
	token->sym = sym;
	token->val = NULL;
	token->next = NULL;
	token->child = NULL;
	return (token);
}
