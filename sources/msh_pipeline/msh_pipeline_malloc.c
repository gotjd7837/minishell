/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   msh_pipeline_malloc.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jho <jho@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 14:26:38 by jho               #+#    #+#             */
/*   Updated: 2023/11/14 14:47:05 by jho              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/msh_pipeline.h"

t_pipeline	*msh_pipeline_malloc(void)
{
	t_pipeline	*pipeline;

	pipeline = (t_pipeline *)malloc(sizeof(pipeline));
	if (pipeline == NULL)
		return (NULL);
	pipeline->tokens = NULL;
	piprline->next = NULL;
	return (pipeline);
}
