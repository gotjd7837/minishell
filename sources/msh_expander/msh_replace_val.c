/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   msh_replace_val.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haekang <haekang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/27 21:04:58 by jho               #+#    #+#             */
/*   Updated: 2023/11/25 10:04:05 by haekang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/msh_expander.h"

int	msh_replace_val(t_token *tokens, t_env *env)
{
	char	*key_env;

	while (tokens != NULL)
	{
		if (msh_strcmp(tokens->val, "$?") == 0)
		{
			tokens = tokens->next;
			continue ;
		}
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
