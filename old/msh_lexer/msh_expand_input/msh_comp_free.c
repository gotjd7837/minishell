/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   msh_comps_free.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jho <jho@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/12 16:48:33 by jho               #+#    #+#             */
/*   Updated: 2023/10/17 16:00:40 by jho              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/minishell.h"

t_comp	*msh_comp_free(t_comp *comps)
{
	t_comp	*node;
	t_comp	*next;

	node = comps;
	while (node != NULL)
	{
		next = node->next;
		free(node->value);
		free(node);
		node = next;
	}
	return (NULL);
}
