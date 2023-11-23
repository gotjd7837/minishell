/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   msh_lex.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haekang <haekang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/27 21:32:25 by jho               #+#    #+#             */
/*   Updated: 2023/11/23 16:19:31 by haekang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/msh_lexer.h"

static int	msh_lex_check_pipe(char *s)
{
	int	idx;

	idx = 0;
	while (msh_is_whitespace(*(s + idx)))
		idx++;
	if (*(s + idx) == '|')
		return (0);
	while (*(s + idx) != '\0')
	{
		if (*(s + idx) == '|' && *(s + idx + 1) == '|')
			return (0);
		idx++;
	}
	if (*(s + idx - 1) == '|')
		return (0);
	return (1);
}

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
		while (*(s + idx) != '|' && *(s + idx) != '\0')
		{
			token_len = msh_lex_tokenize(&pipeline->tokens, s + idx);
			if (token_len == 0)
				return (msh_pipeline_free_list(head));
			idx += token_len;
		}
		if (!msh_pipeline_add_node(&head, pipeline))
			return (msh_pipeline_free_list(head));
		if (*(s + idx) != '\0')
			idx++;
	}
	return (head);
}

t_pipeline	*msh_lex(char *s)
{
	t_pipeline	*pipelines;

	if (s == NULL)
		return (NULL);
	if (!msh_lex_check_pipe(s))
		return (NULL);
	pipelines = msh_tokenize_and_create_pipelines(s);
	if (pipelines == NULL)
		return (NULL);
	return (pipelines);
}
