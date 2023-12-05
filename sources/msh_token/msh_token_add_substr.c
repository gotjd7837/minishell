/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   msh_token_add_substr.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haekang <haekang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/27 17:50:29 by jho               #+#    #+#             */
/*   Updated: 2023/12/05 20:03:59 by haekang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/msh.h"

t_token	*msh_token_add_substr(t_token **token, char *s, int begin, int end)
{
	char	*val;
	t_token	*node;

	val = msh_substr(s, begin, end);
	if (val == NULL)
		return (NULL);
	node = msh_token_malloc_val(val);
	if (node == NULL)
	{
		free(val);
		return (NULL);
	}
	msh_token_add_next(token, node);
	return (node);
}
