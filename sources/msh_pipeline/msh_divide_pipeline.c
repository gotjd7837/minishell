/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   msh_divide_pipeline.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haekang <haekang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 19:21:09 by haekang           #+#    #+#             */
/*   Updated: 2023/11/14 20:32:11 by haekang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/msh_pipeline.h"

// static int	msh_divide_pipeline(t_token **sym_table, t_pipeline **pipelines)
// {
// 	t_pipeline	*pipeline;
// 	t_token		*cur_token;

// 	cur_token = *sym_table;
// 	pipeline = msh_pipeline_malloc();
// 	if (pipeline == NULL)
// 		return (0);
// 	while (cur_token != NULL)
// 	{
// 		if (cur_token->next->sym == PIPE)
// 		{
// 			pipeline->tokens = *sym_table;
// 			*sym_table = cur_token->next->next;
// 			free(cur_token->next->val);
// 			cur_token->next = NULL;
// 			return (1);
// 		}
// 		cur_token = cur_token->next;
// 	}
// 	return (0);
// }





// static t_token	*msh_parse_pipeline(t_token **sym_table, t_token *cur_token)
// {
// 	t_token	*pipeline_tokens;

// 	pipeline_tokens = *sym_table;
// 	*sym_table = cur_token->next->next;
// 	msh_token_free(cur_token->next);
// 	cur_token->next = NULL;
// 	return (pipeline_tokens);
// }

// t_pipeline	*msh_divide_pipeline(t_token **sym_table)
// {
// 	t_pipeline	*pipelines;
// 	t_pipeline	*next_pipeline;
// 	t_token		*cur_token;

// 	pipelines = msh_pipeline_malloc();
// 	cur_token = *sym_table;
// 	while (cur_token != NULL) 
// 	{
// 		if (cur_token->next->sym == PIPE)
// 		{
// 			while ()
// 			pipelines->tokens = msh_parse_pipeline(sym_table, cur_token);
// 		}
// 		cur_token = cur_token->next;
// 	}
// 	return (pipelines);
// }

/*
심볼 테이블이 들어오고 심볼 테이블에서 파이프 토큰이 나올 때 마다 파이프 이전 토큰 리스트를 그대로 잘라서
파이프라인의 토큰 리스트에 이식시킨 후 심볼 테이블의 헤드 노드를 파이프 토큰 다음으로.. 그뒤에 파이프 토큰을 해제함

*/
