/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   msh_lex.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haeseong <haeseong@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/27 21:32:25 by jho               #+#    #+#             */
/*   Updated: 2024/06/12 18:23:04 by haeseong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/msh.h"

static int	msh_lex_check_pipe(char *s)
{
	int	idx;

	idx = 0;
	while (msh_is_whitespace(*(s + idx)))
		idx++;
	if (*(s + idx) == '|')
		return (0);
	while (*(s + idx) != '\0')
		idx++;
	if (*(s + idx - 1) == '|')
		return (0);
	return (1);
}

// 문자열 토큰화 및 pipeline 리스트 생성
static t_pipeline	*msh_tokenize_and_create_pipelines(char *s)
{
	int			idx;
	int			token_len;
	t_pipeline	*head;
	t_pipeline	*pipeline;

	idx = 0;
	head = NULL;
	while (*(s + idx) != '\0')
	{
		pipeline = msh_pipeline_malloc();
		if (pipeline == NULL)
			return (msh_pipeline_free_list(head));
		// '|' 문자를 만나기 전 까지 토큰화
		while (*(s + idx) != '|' && *(s + idx) != '\0')
		{
			// 문자열을 렉싱하여 구분된 토큰을 pipeline 노드의 원소에 add
			token_len = msh_lex_tokenize(&pipeline->tokens, s + idx);
			if (token_len == 0)
				return (msh_pipeline_free_list(head));
			idx += token_len;
		}
		// 반복문 탈출 했으므로 파이프라인 노드를 리스트에 add.
		if (!msh_pipeline_add_node(&head, pipeline))
			return (msh_pipeline_free_list(head));
		if (*(s + idx) == '|')
			idx++;
	}
	return (head);
}

// 문자열을 토큰화하고, pipeline 단위로 토큰 리스트를 담는 리스트 생성
t_pipeline	*msh_lex(char *s)
{
	t_pipeline	*pipelines;

	if (s == NULL)
		return (NULL);
	// '|' 문법 에러 체크
	if (!msh_lex_check_pipe(s))
		return (NULL);
	// 토큰화 및 pipeline 리스트 생성
	pipelines = msh_tokenize_and_create_pipelines(s);
	if (pipelines == NULL)
		return (NULL);
	return (pipelines);
}
