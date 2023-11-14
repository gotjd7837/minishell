/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   msh_pipeline_free.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jho <jho@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 14:28:20 by jho               #+#    #+#             */
/*   Updated: 2023/11/14 14:31:03 by jho              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/msh_pipeline.h"

t_pipeline	*msh_pipeline_free(t_pipeline *pipeline)
{
	t_pipeline	next;

	if (pipeline == NULL)
		return (NULL);
	next = pipeline->next;
	if (pipeline->tokens != NULL)
		msh_token_free_list(pipeline->tokens);
	free(pipeline);
	return (msh_pipeline_free(next));
}
