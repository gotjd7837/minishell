/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   msh_comp_env.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jho <jho@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/12 16:59:16 by jho               #+#    #+#             */
/*   Updated: 2023/10/17 16:00:00 by jho              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/minishell.h"

int	msh_comp_env_end(char *input, int index)
{
	while (!msh_is_special_chr(*(input + index)))
		++index;
	return (index);
}

void	msh_comp_env_substitute(t_comp *comps, t_env *env)
{
	char	*value;

	value = NULL;
	while (comps != NULL)
	{
		if (msh_is_dollar(*(comps->value)))
		{
			value = msh_env_get_value(env, comps->value + 1);
			if (value != NULL)
			{
				free(comps->value);
				comps->value = value;
			}
			else
				*(comps->value) = '\0';
		}
		comps = comps->next;
	}
}

char	*msh_comp_env(char *input, t_env *env)
{
	char	*str;
	int		range[2];
	t_comp	*origin;

	range[0] = 0;
	range[1] = 0;
	origin = NULL;
	while (*(input + range[1]) != '\0')
	{
		if (msh_is_dollar(*(input + range[1])))
		{
			if (!msh_comp_add_node_diff(&origin, input, range[0], range[1]))
				return ((char *)msh_comp_free(origin));
			range[0] = range[1];
			range[1] = msh_comp_env_end(input, range[0] + 1);
			if (!msh_comp_add_node(&origin, input, range[0], range[1]))
				return ((char *)msh_comp_free(origin));
			range[0] = range[1];
		}
		else
			++range[1];
	}
	if (!msh_comp_add_node_diff(&origin, input, range[0], range[1]))
		return ((char *)msh_comp_free(origin));
	msh_comp_env_substitute(origin, env);
	str = msh_comp_union(origin);
	msh_comp_free(origin);
	return (str);
}
