/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   msh_token_count_sym.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haekang <haekang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 14:32:26 by jho               #+#    #+#             */
/*   Updated: 2023/12/05 19:38:15 by haekang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/msh.h"

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
