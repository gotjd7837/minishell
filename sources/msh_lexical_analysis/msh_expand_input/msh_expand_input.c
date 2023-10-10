/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   msh_expand_input.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jho <jho@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 12:11:28 by jho               #+#    #+#             */
/*   Updated: 2023/10/10 13:52:38 by jho              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/minishell.h"

char	*msh_expand_input(char *input)
{
	t_comp	*comps;
	char	*result;

	result = NULL;
	comps = msh_divide_comps(input);
	if (comps == NULL)
		printf("Syntax Error\n");
	else
	{
		while (comps != 0)
		{
			printf("%s\n", comps->value);
			comps = comps->next;
		}
	}
	return (result);
}
