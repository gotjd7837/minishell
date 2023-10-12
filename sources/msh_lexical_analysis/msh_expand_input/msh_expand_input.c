/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   msh_expand_input.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haekang <haekang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
<<<<<<< HEAD:sources/utils/msh_substr.c
/*   Created: 2023/08/29 20:30:58 by jho               #+#    #+#             */
/*   Updated: 2023/10/10 18:03:58 by haekang          ###   ########.fr       */
=======
/*   Created: 2023/10/10 12:11:28 by jho               #+#    #+#             */
/*   Updated: 2023/10/10 13:52:38 by jho              ###   ########.fr       */
>>>>>>> master:sources/msh_lexical_analysis/msh_expand_input/msh_expand_input.c
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/minishell.h"

char	*msh_expand_input(char *input)
{
<<<<<<< HEAD:sources/utils/msh_substr.c
	int		i;
	char	*substr;

	i = 0;
	substr = malloc(sizeof(char) * (end_idx - start_idx + 1));
	if (substr == 0)
		return (0);
	while (start_idx < end_idx)
	{
		substr[i] = s[start_idx];
		++i;
		++start_idx;
	}
	substr[i] = '\0';
	return (substr);
=======
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
>>>>>>> master:sources/msh_lexical_analysis/msh_expand_input/msh_expand_input.c
}
