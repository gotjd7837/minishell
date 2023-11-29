/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   msh_pipeline_add_heredoc.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jho <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 15:23:37 by jho               #+#    #+#             */
/*   Updated: 2023/11/29 15:26:01 by jho              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/msh_pipeline.h"

int	msh_pipeline_add_heredoc(t_pipeline *pipeline, t_heredoc *heredoc)
{
	t_heredoc	*last;

	if (pipeline == NULL)
		return (0);
	if (pipeline->heredoc == NULL)
		pipeline->heredoc = heredoc;
	else
	{
		last = pipeline->heredoc;
		while (last->next != NULL)
			last = last->next;
		last->next = heredoc;
	}
	return (1);
}
