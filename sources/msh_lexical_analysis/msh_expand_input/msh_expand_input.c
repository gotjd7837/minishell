/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   msh_expand_input.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jho <jho@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 12:11:28 by jho               #+#    #+#             */
/*   Updated: 2023/10/10 14:35:41 by jho              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/minishell.h"


void	msh_manufacture_sqoute(char *value)
{
	int	index;

	index = 1;
	while (*(value + index) != '\'')
	{
		*(value + index - 1) = *(value + index);
		++index;
	}
	*(value + index - 1) = '\0';
}
/*
void	msh_manufacture_dqoute(char *value)
{

}

void	msh_manufacture_no_qoute(char *value)
{

}
*/

int	msh_manufacture_comps(t_comp **origin)
{
	t_comp	*comps;

	comps = *origin;
	while (comps != NULL)
	{
		if (msh_is_sqoute(*(comps->value)))
			msh_manufacture_sqoute(comps->value);
		//else if (msh_is_dqoute(*(comps->value)))
		//	msh_manufacture_dqoute(comp->value);
		//else
		//	msh_manufacture_no_qoute(comp->value);
		comps = comps->next;
	}
	return (1);
}

char	*msh_expand_input(char *input)
{
	t_comp	*comps;
	char	*result;

	result = NULL;
	comps = msh_divide_comps(input);
	if (comps == NULL)
		return (NULL);
	msh_manufacture_comps(&comps);
	while (comps != NULL)
	{
		printf("Value : %s\n", comps->value);
		comps = comps->next;
	}
	return (result);
}
