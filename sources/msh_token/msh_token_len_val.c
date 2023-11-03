/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   msh_token_len_val.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jho <jho@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 10:18:36 by jho               #+#    #+#             */
/*   Updated: 2023/10/26 12:25:37 by jho              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/msh_token.h"
#include "../../includes/msh_util.h"

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
