/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   msh_pipeline_free_list.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haekang <haekang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 14:28:20 by jho               #+#    #+#             */
/*   Updated: 2023/11/23 13:54:48 by haekang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/msh_pipeline.h"

t_pipeline	*msh_pipeline_free_list(t_pipeline *pipeline)
{
	t_pipeline	*next;

	if (pipeline == NULL)
		return (NULL);
	next = pipeline->next;
	if (pipeline->tokens != NULL)
		msh_token_free_list(pipeline->tokens);
	free(pipeline);
	return (msh_pipeline_free_list(next));
}
