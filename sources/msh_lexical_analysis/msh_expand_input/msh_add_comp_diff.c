/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   msh_add_comp_diff.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jho <jho@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 16:32:25 by jho               #+#    #+#             */
/*   Updated: 2023/10/10 16:33:17 by jho              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/minishell.h"

void	msh_add_comp_diff(t_comp **comps, char *input, int begin, int end)
{
	if (begin != end)
		msh_add_comp(comps, input, begin, end);
}
