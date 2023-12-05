/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   msh_pipeline_malloc.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haekang <haekang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 14:26:38 by jho               #+#    #+#             */
/*   Updated: 2023/12/05 19:37:40 by haekang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/msh.h"

t_pipeline	*msh_pipeline_malloc(void)
{
	t_pipeline	*pipeline;

	pipeline = (t_pipeline *)malloc(sizeof(t_pipeline));
	if (pipeline == NULL)
		return (NULL);
	pipeline->tokens = NULL;
	pipeline->next = NULL;
	pipeline->heredoc = NULL;
	pipeline->pid = -1;
	return (pipeline);
}
