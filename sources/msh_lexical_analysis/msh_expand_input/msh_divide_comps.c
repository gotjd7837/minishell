/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   msh_divide_comps.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jho <jho@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 13:33:28 by jho               #+#    #+#             */
/*   Updated: 2023/10/10 14:02:01 by jho              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/minishell.h"

void	msh_add_comp_diff(t_comp **comps, char *input, int begin, int end)
{
	if (begin != end)
		msh_add_comp(comps, input, begin, end);
}

t_comp	*msh_divide_comps(char *input)
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
			msh_add_comp_diff(&comps, input, range[0], range[1]);
			range[0] = range[1];
			range[1] = validator(input, range[0] + 1) + 1;
			if (range[1] == 0)
				return (NULL);
			msh_add_comp(&comps, input, range[0], range[1]);
			range[0] = range[1];
		}
		else
			++range[1];
	}
	msh_add_comp_diff(&comps, input, range[0], range[1]);
	return (comps);
}
