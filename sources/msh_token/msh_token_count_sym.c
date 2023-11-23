/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   msh_token_count_sym.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jho <jho@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 14:32:26 by jho               #+#    #+#             */
/*   Updated: 2023/11/23 14:33:31 by jho              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/msh_token.h"

int	msh_token_count_sym(t_token *tokens, t_sym sym)
{
	int	count;

	count = 0;
	while (tokens != NULL)
	{
		count += tokens->sym == sym;
		tokens = tokens->next;
	}
	return (count);
}
