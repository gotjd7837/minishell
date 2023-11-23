/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   msh_pipeline_last.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jho <jho@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 14:26:12 by jho               #+#    #+#             */
/*   Updated: 2023/11/23 14:31:28 by jho              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/msh_pipeline.h"

t_pipeline	*msh_pipeline_last(t_pipeline *pipelines)
{
	if (pipelines == NULL)
		return (NULL);
	while (pipelines->next != NULL)
		pipelines = pipelines->next;
	return (pipelines);
}
