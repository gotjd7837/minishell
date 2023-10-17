/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   msh_comp_union.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haekang <haekang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/12 16:47:41 by jho               #+#    #+#             */
/*   Updated: 2023/10/17 18:35:04 by haekang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/minishell.h"

static size_t	msh_comps_total_len(t_comp *origin)
{
	t_comp	*comps;
	size_t	total_len;

	total_len = 0;
	comps = origin;
	while (comps != NULL)
	{
		total_len += msh_strlen(comps->value);
		comps = comps->next;
	}
	return (total_len);
}

char	*msh_comp_union(t_comp *origin)
{
	size_t	len;
	size_t	total_len;
	t_comp	*comps;
	char	*unioned_str;

	total_len = msh_comps_total_len(origin);
	comps = origin;
	unioned_str = malloc(total_len + 1);
	if (unioned_str == NULL)
	{
		msh_comp_free(origin);
		return (NULL);
	}
	total_len = 0;
	while (origin != NULL)
	{
		len = msh_strlen(origin->value);
		msh_strncpy(unioned_str + total_len, origin->value, len);
		total_len += len;
		origin = origin->next;
	}
	*(unioned_str + total_len) = '\0';
	return (unioned_str);
}
