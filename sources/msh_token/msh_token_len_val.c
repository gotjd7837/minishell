/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   msh_token_len_val.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haekang <haekang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 10:18:36 by jho               #+#    #+#             */
/*   Updated: 2023/12/05 19:38:49 by haekang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/msh.h"

int	msh_token_len_val(t_token *token)
{
	int	len;

	len = 0;
	while (token != NULL)
	{
		if (token->val == NULL)
			return (-1);
		len += msh_strlen(token->val);
		token = token->next;
	}
	return (len);
}
