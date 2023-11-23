/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   msh_pipeline_last.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haekang <haekang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 13:56:54 by haekang           #+#    #+#             */
/*   Updated: 2023/11/23 13:57:08 by haekang          ###   ########.fr       */
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
