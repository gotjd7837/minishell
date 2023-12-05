/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   msh_token_union_val.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haekang <haekang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 10:11:24 by jho               #+#    #+#             */
/*   Updated: 2023/12/05 19:39:20 by haekang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/msh.h"

char	*msh_token_union_val(t_token *token)
{
	int		len;
	char	*unioned;

	if (token == NULL)
		return (NULL);
	len = msh_token_len_val(token);
	if (len == -1)
		return (NULL);
	unioned = malloc(sizeof(char) * (len + 1));
	if (unioned == NULL)
		return (NULL);
	len = 0;
	while (token != NULL)
	{
		msh_strcpy(unioned + len, token->val);
		len += msh_strlen(token->val);
		token = token->next;
	}
	*(unioned + len) = '\0';
	return (unioned);
}
