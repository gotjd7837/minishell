/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   msh_comp_expand.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jho <jho@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/12 18:01:19 by jho               #+#    #+#             */
/*   Updated: 2023/10/12 18:27:14 by jho              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/minishell.h"

char	*msh_comp_expand(t_comp *origin, t_env *env)
{
	t_comp	*comps;
	char	*expanded_str;

	comps = origin;
	while (comps != NULL)
	{
		if (msh_is_sqoute(*(comps->value)))
			msh_strtrim_bothends(comps->value);
		else if (msh_is_dqoute(*(comps->value)))
		{
			msh_strtrim_bothends(comps->value);
			comps->value = msh_comp_env(comps->value, env);
		}
		else
			comps->value = msh_comp_env(comps->value, env);
		comps = comps->next;
	}
	expanded_str = msh_comp_union(origin);
	return (expanded_str);
}
