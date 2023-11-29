/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   msh_pipeline_free_list.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haekang <haekang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 14:28:20 by jho               #+#    #+#             */
/*   Updated: 2023/11/29 16:51:51 by jho              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/msh_pipeline.h"

void		msh_pipeline_free_list_heredoc(t_heredoc *heredoc)
{
	t_heredoc	*next;

	if (heredoc == NULL)
		return ;
	next = heredoc->next;
	if (heredoc->name != NULL)
	{
		unlink(heredoc->name);
		free(heredoc->name);
	}
	free(heredoc);
	msh_pipeline_free_list_heredoc(next);
}

t_pipeline	*msh_pipeline_free_list(t_pipeline *pipeline)
{
	t_pipeline	*next;

	if (pipeline == NULL)
		return (NULL);
	next = pipeline->next;
	if (pipeline->tokens != NULL)
		msh_token_free_list(pipeline->tokens);
	if (pipeline->heredoc != NULL)
		msh_pipeline_free_list_heredoc(pipeline->heredoc);
	free(pipeline);
	return (msh_pipeline_free_list(next));
}
