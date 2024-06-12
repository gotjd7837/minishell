/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   msh_replace_tokenize.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haeseong <haeseong@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/27 21:06:26 by jho               #+#    #+#             */
/*   Updated: 2024/06/12 16:01:31 by haeseong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/msh.h"

int	msh_replace_tokenize_dollar(t_token **tokens, char *s, int begin, int end)
{
	// '$' 이전의 문자열을 토큰으로 추가
	if (begin != end
		&& !msh_token_add_substr(tokens, s, begin, end))
		return (0);
	// '$' 이후 문자열에서 환경 변수의 key값까지 인덱스 처리
	begin = end++;
	while (*(s + end) != '\0'
		&& !msh_is_charset(*(s + end), " $|&\t\'\""))
		++end;
	// "$ + 환경 변수"를 토큰으로 추가
	if (!msh_token_add_substr(tokens, s, begin, end))
		return (0);
	return (end);
}

// 문자열을 환경 변수('$') 기준으로 토큰화해서 반환
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
			// 문자열에서 '$'를 발견하면 토큰화 해서 token_env에 저장
			range[1] = msh_replace_tokenize_dollar(&token_env, s,
					range[0], range[1]);
			if (range[1] == 0)
				return (msh_token_free_list(token_env));
			range[0] = range[1];
		}
		else
			++range[1];
	}
	// 남은 문자열 토큰으로 추가
	if ((range[0] != range[1])
		&& !msh_token_add_substr(&token_env, s, range[0], range[1]))
		return (msh_token_free_list(token_env));
	return (token_env);
}
