/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   msh_manipulate_comps.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jho <jho@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 13:35:56 by jho               #+#    #+#             */
/*   Updated: 2023/10/12 12:11:52 by jho              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/minishell.h"

t_comp	*msh_last_comp(t_comp *comps)
{
	if (comps == 0)
		return (0);
	while (comps->next != NULL)
		comps = comps->next;
	return (comps);
}

int	msh_add_comp(t_comp **origin, char *input, int begin, int end)
{
	char	*value;
	t_comp	*comp;
	t_comp	*comps;

	value = malloc(end - begin + 1);
	msh_strncpy(value, input + begin, end - begin);
	*(value + end - begin) = '\0';
	comp = malloc(sizeof(t_comp));
	comp->value = value;
	comp->next = 0;
	if (*origin == 0)
		*origin = comp;
	else
	{
		comps = msh_last_comp(*origin);
		comps->next = comp;
	}
	return (1);
}
