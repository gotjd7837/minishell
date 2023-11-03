/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   msh_replace_val.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jho <jho@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/27 21:04:58 by jho               #+#    #+#             */
/*   Updated: 2023/10/27 21:05:13 by jho              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/msh_expander.h"

int	msh_replace_val(t_token *tokens, t_env *env)
{
	char	*key_env;

	while (tokens != NULL)
	{
		if (*(tokens->val) == '$' && *(tokens->val + 1) != '\0')
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
