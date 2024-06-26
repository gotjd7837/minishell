/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   msh_replace_env.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haeseong <haeseong@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 17:23:05 by jho               #+#    #+#             */
/*   Updated: 2024/06/12 16:02:39 by haeseong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/msh.h"

// 매개 변수로 받은 토큰의 환경 변수 확장
int	msh_replace_env_2(t_token *tokens_cpy, t_env *env)
{
	t_token	*tokens_env;

	// 해당 토큰을 환경 변수('$')를 기준으로 다시 토큰화하여 리스트로 반환 
	tokens_env = msh_replace_tokenize(tokens_cpy->val);
	if (tokens_env == NULL)
		return (0);
	// 토큰에서 환경 변수를 확장
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
		// single quote로 감싸지지 않은 토큰만 확장 수행
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
