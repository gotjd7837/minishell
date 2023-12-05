/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   msh_token_malloc_symval.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haekang <haekang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 09:09:40 by jho               #+#    #+#             */
/*   Updated: 2023/12/05 19:38:58 by haekang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/msh.h"

t_token	*msh_token_malloc_symval(t_sym sym, char *val)
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
