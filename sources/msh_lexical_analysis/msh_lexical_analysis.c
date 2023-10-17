/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   msh_lexical_analysis.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jho <jho@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 10:40:49 by jho               #+#    #+#             */
/*   Updated: 2023/10/17 14:30:32 by jho              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

t_token	*msh_lexical_analysis(char *input, t_env *env)
{
	char	*expanded;

	expanded = msh_expand_input(input, env);
	if (expanded == NULL)
	{
		printf("Error\n");
		return (NULL);
	}
	printf("Expanded : %s\n", expanded);
	free(expanded);
	return (0);
}
