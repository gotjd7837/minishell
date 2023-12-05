/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   msh_vqoutes_idx.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haekang <haekang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 15:37:15 by jho               #+#    #+#             */
/*   Updated: 2023/12/05 19:35:25 by haekang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/msh.h"

void	msh_vqoutes_idx(char *s, int **v_idx)
{
	int	s_idx;
	int	*v_idx_cpy;
	int	sqoute_open;
	int	dqoute_open;

	s_idx = 0;
	v_idx_cpy = *v_idx;
	sqoute_open = 0;
	dqoute_open = 0;
	while (*(s + s_idx) != '\0')
	{
		if (*(s + s_idx) == '\'' && dqoute_open == 0)
		{
			sqoute_open = !sqoute_open;
			*v_idx_cpy = s_idx;
			++v_idx_cpy;
		}
		else if (*(s + s_idx) == '\"' && sqoute_open == 0)
		{
			dqoute_open = !dqoute_open;
			*v_idx_cpy = s_idx;
			++v_idx_cpy;
		}
		++s_idx;
	}
}
