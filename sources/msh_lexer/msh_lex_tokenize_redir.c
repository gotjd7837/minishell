/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   msh_lex_tokenize_redir.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haeseong <haeseong@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/28 08:49:22 by jho               #+#    #+#             */
/*   Updated: 2024/06/12 18:54:22 by haeseong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/msh.h"

// quote 처리를 포함해서 토큰화할 지점까지의 idx를 계산하는 함수
int	msh_lex_tokenize_redir_qoutes_find_last_idx(char *s)
{
	int	qoute_idx;
	int	last_idx;

	qoute_idx = 0;
	last_idx = 0;
	while (!msh_is_charset(*(s + last_idx), "|<> ") && *(s + last_idx) != '\0')
	{
		// quote를 만나면
		if (msh_is_charset(*(s + last_idx), "\'\""))
		{
			qoute_idx = last_idx++;
			// 다음 quote를 만날때 까지 idx++
			while (*(s + last_idx) != *(s + qoute_idx))
				++last_idx;
		}
		++last_idx;
	}
	return (last_idx);
}

char	*msh_lex_tokenize_redir_clear_qoutes(char *s)
{
	t_token	*tokens;

	tokens = msh_vqoutes(s);
	if (!msh_trim_both_end(&tokens))
		return (NULL);
	free(s);
	s = msh_token_union_val(tokens);
	msh_token_free_list(tokens);
	return (s);
}

int	msh_lex_tokenize_redir(t_token **sym_table, char *s)
{
	int		idx;
	t_token	*token;

	idx = 1;
	// heredoc, 리다이렉션 기호가 두개일 때 처리
	if (*(s + 1) == '<' || *(s + 1) == '>')
		idx = 2;
	while (msh_is_whitespace(*(s + idx)) && *(s + idx) != '\0')
		++idx;
	// 문자열에서 토큰화할 지점까지의 인덱스를 찾음
	idx += msh_lex_tokenize_redir_qoutes_find_last_idx(s + idx);
	token = msh_token_malloc_sym(REDIR);
	if (token == NULL)
		return (0);
	// 토큰 노드의 원소에 문자열 할당 및 quote 삭제
	token->val = msh_substr(s, 0, idx);
	token->val = msh_lex_tokenize_redir_clear_qoutes(token->val);
	if (token->val == NULL)
	{
		msh_token_free(token);
		return (0);
	}
	// 토큰 리스트에 노드 add
	msh_token_add_next(sym_table, token);
	return (idx);
}
