/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   msh_comp_expand.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haekang <haekang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/12 18:01:19 by jho               #+#    #+#             */
/*   Updated: 2023/10/26 08:28:54 by jho              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/minishell.h"

static int	msh_expand_and_process_comp(t_comp *comp, t_env *env)
{
	char	*value;

	value = NULL;
	if (msh_is_dqoute(*(comp->value)))
	{
		value = msh_comp_env(comp->value, env, NULL);
		free(comp->value);
		comp->value = value;
		if (comp->value == NULL)
			return ((int)msh_comp_free(comp));
	}
	else if (!msh_is_sqoute(*(comp->value)))
	{
		value = msh_comp_env(comp->value, env, NULL);
		free(comp->value);
		comp->value = value;
		if (comp->value == NULL)
			return ((int)msh_comp_free(comp));
	}
	return (1);
}

int	msh_comp_expand(t_comp *origin, t_env *env)
{
	t_comp	*comps;

	comps = origin;
	while (comps != NULL)
	{
		if (!msh_expand_and_process_comp(comps, env))
			return (0);
		comps = comps->next;
	}
	return (1);
}
