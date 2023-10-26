/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   msh_comp_last_node.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jho <jho@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/12 18:04:39 by jho               #+#    #+#             */
/*   Updated: 2023/10/12 18:05:02 by jho              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/minishell.h"

t_comp	*msh_comp_last_node(t_comp *comps)
{
	if (comps == 0)
		return (0);
	while (comps->next != NULL)
		comps = comps->next;
	return (comps);
}
