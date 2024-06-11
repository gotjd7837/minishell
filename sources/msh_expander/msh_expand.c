/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   msh_expand.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haekang <haekang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 09:58:12 by jho               #+#    #+#             */
/*   Updated: 2024/06/11 21:33:16 by haekang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/msh.h"

// 토큰 양쪽 끝 quote를 제거하는 함수
int	msh_trim_both_end(t_token **tokens)
{
	t_token	*tokens_cpy;
	char	*trim_val;

	tokens_cpy = *tokens;
	while (tokens_cpy != NULL)
	{
		if (*(tokens_cpy->val) == '\'' || *(tokens_cpy->val) == '\"')
		{
			trim_val = msh_substr
				(tokens_cpy->val, 1, msh_strlen(tokens_cpy->val) - 1);
			if (trim_val == NULL)
				return (0);
			free(tokens_cpy->val);
			tokens_cpy->val = trim_val;
		}
		tokens_cpy = tokens_cpy->next;
	}
	return (1);
}

char	*msh_expand(char *s, t_env *env)
{
	t_token	*tokens;
	char	*expanded;

	// 입력 문자열을 quote 기준으로 토큰화
	tokens = msh_vqoutes(s);
	if (tokens == NULL)
		return (NULL);
	// 토큰 리스트 내의 환경 변수를 확장
	if (!msh_replace_env(&tokens, env))
		return (NULL);
	expanded = msh_token_union_val(tokens);
	if (expanded == NULL)
		return (NULL);
	msh_token_free_list(tokens);
	// 확장된 문자열 반환
	return (expanded);
}
