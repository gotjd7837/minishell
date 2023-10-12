/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   msh_comp_add_diff.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jho <jho@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/12 16:51:25 by jho               #+#    #+#             */
/*   Updated: 2023/10/12 18:10:44 by jho              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/minishell.h"

void	msh_comp_add_node_diff(t_comp **comps, char *input, int begin, int end)
{
	if (begin != end)
		msh_comp_add_node(comps, input, begin, end);
}
