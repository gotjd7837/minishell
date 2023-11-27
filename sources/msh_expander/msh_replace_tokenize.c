/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   msh_replace_tokenize.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haekang <haekang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/27 21:06:26 by jho               #+#    #+#             */
/*   Updated: 2023/11/27 19:16:17 by haekang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/msh_expander.h"

int	msh_replace_tokenize_dollar(t_token **tokens, char *s, int begin, int end)
{
	if (begin != end
		&& !msh_token_add_substr(tokens, s, begin, end))
		return (0);
	begin = end++;
	while (*(s + end) != '\0'
		&& !msh_is_charset(*(s + end), " $|&\t\'\""))
		++end;
	if (!msh_token_add_substr(tokens, s, begin, end))
		return (0);
	return (end);
}

t_token	*msh_replace_tokenize(char *s)
{
	t_token	*token_env;
	int		range[2];

	range[0] = 0;
	range[1] = 0;
	token_env = NULL;
	while (*(s + range[1]) != '\0')
	{
		if (*(s + range[1]) == '$')
		{
			range[1] = msh_replace_tokenize_dollar(&token_env, s,
					range[0], range[1]);
			if (range[1] == 0)
				return (msh_token_free_list(token_env));
			range[0] = range[1];
		}
		else
			++range[1];
	}
	if ((range[0] != range[1])
		&& !msh_token_add_substr(&token_env, s, range[0], range[1]))
		return (msh_token_free_list(token_env));
	return (token_env);
}
