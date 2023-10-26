/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   msh_token_last.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jho <jho@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 09:12:15 by jho               #+#    #+#             */
/*   Updated: 2023/10/26 09:13:16 by jho              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "msh_token.h"

t_token	*msh_token_last(t_token *token)
{
	if (token == NULL)
		return (NULL);
	while (token->next != NULL)
		token = token->next;
	return (token);
}
