/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   msh_token_malloc.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haekang <haekang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 09:09:15 by jho               #+#    #+#             */
/*   Updated: 2023/12/05 19:39:05 by haekang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/msh.h"

t_token	*msh_token_malloc(void)
{
	t_token	*token;

	token = malloc(sizeof(t_token));
	if (token == NULL)
		return (NULL);
	token->sym = UNDEFINED;
	token->val = NULL;
	token->next = NULL;
	token->child = NULL;
	return (token);
}
