/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   msh_comp_expand.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jho <jho@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/12 18:01:19 by jho               #+#    #+#             */
/*   Updated: 2023/10/17 16:00:22 by jho              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/minishell.h"

int msh_comp_expand(t_comp *origin, t_env *env)
{
	char	*value;
	t_comp	*comps;

	comps = origin;
	value = NULL;
	while (comps != NULL)
	{
		if (msh_is_sqoute(*(comps->value)))
			msh_strtrim_bothends(comps->value);
		else if (msh_is_dqoute(*(comps->value)))
		{
			msh_strtrim_bothends(comps->value);
			value = msh_comp_env(comps->value, env);
			free(comps->value);
			comps->value = value;
			if (comps->value == NULL)
				return ((int)msh_comp_free(comps));
		}
		else
		{
			value = msh_comp_env(comps->value, env);
			free(comps->value);
			comps->value = value;
			if (comps->value == NULL)
				return ((int)msh_comp_free(comps));
		}
		comps = comps->next;
	}
	return (1);
}
