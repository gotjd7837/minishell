/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   msh_vqoutes.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haekang <haekang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 15:39:17 by jho               #+#    #+#             */
/*   Updated: 2023/12/05 19:36:04 by haekang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/msh.h"

t_token	*msh_vqoutes(char *s)
{
	int		num;
	int		*idx;
	t_token	*tokens;

	num = msh_vqoutes_num(s);
	if (num == -1)
		return (NULL);
	idx = malloc(sizeof(int) * num);
	if (idx == NULL)
		return (NULL);
	msh_vqoutes_idx(s, &idx);
	tokens = NULL;
	tokens = msh_vqoutes_tokenize(s, idx, num);
	free(idx);
	return (tokens);
}
