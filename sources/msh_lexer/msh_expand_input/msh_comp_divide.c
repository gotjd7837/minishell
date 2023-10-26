/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   msh_comp_divide.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jho <jho@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/12 18:00:27 by jho               #+#    #+#             */
/*   Updated: 2023/10/17 14:45:08 by jho              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/minishell.h"

int	msh_validate_input(t_comp **lst, char *s, int *range, int (*v)(char *, int))
{
	if (!msh_comp_add_node_diff(lst, s, range[0], range[1]))
		return (0);
	range[0] = range[1];
	range[1] = v(s, range[0] + 1) + 1;
	if (range[1] == 0)
		return (0);
	if (!msh_comp_add_node(lst, s, range[0], range[1]))
		return (0);
	range[0] = range[1];
	return (1);
}

t_comp	*msh_comp_divide(char *input)
{
	int		range[2];
	t_comp	*comps;
	int		(*validator)(char *, int);

	range[0] = 0;
	range[1] = 0;
	comps = NULL;
	while (*(input + range[1]) != '\0')
	{
		validator = msh_get_validator(*(input + range[1]));
		if (validator != NULL)
		{
			if (!msh_validate_input(&comps, input, range, validator))
				return (msh_comp_free(comps));
		}
		else
			++range[1];
	}
	if (!msh_comp_add_node_diff(&comps, input, range[0], range[1]))
		return (msh_comp_free(comps));
	return (comps);
}
