/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   msh_replace_env.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jho <jho@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 17:23:05 by jho               #+#    #+#             */
/*   Updated: 2023/10/27 20:38:50 by jho              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/msh_expander.h"
#include <stdio.h>
int	msh_is_charset(char c, char *set)
{
	while (*set != '\0')
	{
		if (c == *set)
			return (1);
		++set;
	}
	return (0);
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
			if (range[0] != range[1])
			{
				if (!msh_token_add_substr(&token_env, s, range[0], range[1]))
					return (msh_token_free_list(token_env));
				range[0] = range[1];
			}
			++range[1];
			while (*(s + range[1]) != '\0'
					&& !msh_is_charset(*(s + range[1]), " $|&\t\'\""))
				++range[1];
			if (!msh_token_add_substr(&token_env, s, range[0], range[1]))
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

int	msh_replace_val(t_token *tokens, t_env *env)
{
	char	*key_env;

	while (tokens != NULL)
	{
		if (*(tokens->val) == '$' && *(tokens->val + 1) != '\0')
		{
			key_env = msh_substr(tokens->val, 1, msh_strlen(tokens->val) + 1);
			free(tokens->val);
			tokens->val = msh_env_get_value(env, key_env);
			free(key_env);
		}
		tokens = tokens->next;
	}
	return (1);
}

int	msh_replace_env(t_token **tokens, t_env *env)
{
	t_token	*tokens_cpy;
	t_token	*tokens_env;

	if (tokens == NULL)
		return (0);
	tokens_cpy = *tokens;
	while (tokens_cpy != NULL)
	{
		if (tokens_cpy->val == NULL)
			return (0);
		if (*(tokens_cpy->val) != '\'')
		{
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
		}
		tokens_cpy = tokens_cpy->next;
	}
	return (1);
}
