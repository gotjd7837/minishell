/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   msh_replace_val.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haekang <haekang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/27 21:04:58 by jho               #+#    #+#             */
/*   Updated: 2023/12/05 19:35:17 by haekang          ###   ########.fr       */
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

int	msh_replace_val(t_token *tokens, t_env *env)
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
