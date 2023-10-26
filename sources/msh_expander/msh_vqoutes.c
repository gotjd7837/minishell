/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   msh_vqoutes.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jho <jho@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 15:39:17 by jho               #+#    #+#             */
/*   Updated: 2023/10/26 15:39:38 by jho              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/msh_expander.h"

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
