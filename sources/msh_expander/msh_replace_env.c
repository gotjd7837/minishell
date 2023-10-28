/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   msh_replace_env.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jho <jho@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 17:23:05 by jho               #+#    #+#             */
/*   Updated: 2023/10/27 21:30:15 by jho              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/msh_expander.h"

int	msh_replace_env_2(t_token *tokens_cpy, t_env *env)
{
	t_token	*tokens_env;

	tokens_env = msh_replace_tokenize(tokens_cpy->val);
	if (tokens_env == NULL)
		return (0);
	if (!msh_replace_val(tokens_env, env))
	{
		msh_token_free_list(tokens_env);
		return (0);
	}
	free(tokens_cpy->val);
	tokens_cpy->val = msh_token_union_val(tokens_env);
	msh_token_free_list(tokens_env);
	return (1);
}

int	msh_replace_env(t_token **tokens, t_env *env)
{
	t_token	*tokens_cpy;

	if (tokens == NULL)
		return (0);
	tokens_cpy = *tokens;
	while (tokens_cpy != NULL)
	{
		if (tokens_cpy->val == NULL)
			return (0);
		if (*(tokens_cpy->val) != '\'')
		{
			if (!msh_replace_env_2(tokens_cpy, env))
			{
				msh_token_free_list(tokens_cpy);
				return (0);
			}
		}
		tokens_cpy = tokens_cpy->next;
	}
	return (1);
}
