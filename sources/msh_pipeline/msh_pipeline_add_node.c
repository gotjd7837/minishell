/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   msh_pipeline_add_node.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haekang <haekang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 13:56:13 by haekang           #+#    #+#             */
/*   Updated: 2023/12/05 19:37:27 by haekang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/msh.h"

int	msh_pipeline_add_node(t_pipeline **head, t_pipeline *pipeline)
{
	t_pipeline	*last;

	if (head == NULL || pipeline == NULL)
		return (0);
	if (*head == NULL)
		*head = pipeline;
	else
	{
		last = msh_pipeline_last(*head);
		last->next = pipeline;
	}
	return (1);
}
