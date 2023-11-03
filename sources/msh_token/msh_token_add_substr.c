/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   msh_token_add_substr.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jho <jho@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/27 17:50:29 by jho               #+#    #+#             */
/*   Updated: 2023/10/27 18:36:45 by jho              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/msh_token.h"
#include "../../includes/msh_util.h"

t_token	*msh_token_add_substr(t_token **tokens, char *s, int begin, int end)
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
