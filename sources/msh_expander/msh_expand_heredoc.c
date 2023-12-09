/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   msh_expand_heredoc.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haekang <haekang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/01 14:41:04 by jho               #+#    #+#             */
/*   Updated: 2023/12/05 19:35:04 by haekang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/msh.h"

static int	msh_replace_val_exit_status(t_token *token)
{
	char	*res;
	char	*exit_status;
	char	*tail;

	exit_status = msh_itoa(g_exit_status);
	if (*(token->val + 2) != '\0')
	{
		tail = msh_substr(token->val, 2, msh_strlen(token->val));
		if (tail == NULL)
			return (0);
		res = msh_strjoin(exit_status, tail);
		if (res == NULL)
			return (0);
		free(token->val);
		token->val = res;
	}
	else
	{
		free(token->val);
		token->val = exit_status;
	}
	return (1);
}

int	msh_replace_val_heredoc(t_token *tokens, t_env *env)
{
	char	*key_env;

	while (tokens != NULL)
	{
		if (*(tokens->val) == '$' && *(tokens->val + 1) == '?')
		{
			if (!msh_replace_val_exit_status(tokens))
				return (0);
		}
		else if (*(tokens->val) == '$' && *(tokens->val + 1) != '\0')
		{
			key_env = msh_substr(tokens->val, 1, msh_strlen(tokens->val) + 1);
			if (key_env == NULL)
				return (0);
			free(tokens->val);
			tokens->val = msh_env_get_value(env, key_env);
			free(key_env);
		}
		tokens = tokens->next;
	}
	return (1);
}

int	msh_replace_env_heredoc(t_token *tokens_cpy, t_env *env)
{
	t_token	*tokens_env;

	tokens_env = msh_replace_tokenize(tokens_cpy->val);
	if (tokens_env == NULL)
		return (0);
	if (!msh_replace_val_heredoc(tokens_env, env))
	{
		msh_token_free_list(tokens_env);
		return (0);
	}
	free(tokens_cpy->val);
	tokens_cpy->val = msh_token_union_val(tokens_env);
	msh_token_free_list(tokens_env);
	return (1);
}

char	*msh_expand_heredoc_add_lf(char *s)
{
	char	*added;

	added = malloc(sizeof(char) * msh_strlen(s) + 2);
	msh_strcpy(added, s);
	added[msh_strlen(s)] = '\n';
	added[msh_strlen(s) + 1] = '\0';
	return (added);
}

char	*msh_expand_heredoc(char *s, t_env *env)
{
	t_token	*tokens;
	char	*expanded;

	if (*s == '\n')
		return (s);
	tokens = msh_token_malloc_val(s);
	*(tokens->val + msh_strlen(tokens->val) - 1) = '\0';
	if (tokens == NULL)
		return (NULL);
	if (!msh_replace_env_heredoc(tokens, env))
		return (NULL);
	expanded = msh_expand_heredoc_add_lf(tokens->val);
	free(tokens);
	return (expanded);
}
