/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   msh_vqoutes_add_token.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jho <jho@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 15:37:52 by jho               #+#    #+#             */
/*   Updated: 2023/10/26 15:41:56 by jho              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/msh_expander.h"

t_token	*msh_vqoutes_add_token(t_token **tokens, char *s, int begin, int end)
{
	char	*val;
	t_token	*token;

	val = msh_substr(s, begin, end);
	if (val == NULL)
		return (NULL);
	token = msh_token_malloc_val(val);
	if (token == NULL)
	{
		free(val);
		return (NULL);
	}
	msh_token_add_next(tokens, token);
	return (token);
}
