/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   msh_main.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jho <jho@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/25 16:14:20 by jho               #+#    #+#             */
/*   Updated: 2023/08/29 21:08:37 by jho              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int	main(void)
{
	char	*input;
	t_token	*tokens;

	while (1)
	{
		input = readline("$> ");
		tokens = msh_lexical_analysis(input);
		while (tokens != 0)
		{
			printf("%-15u%-15s\n", tokens->symbol, tokens->value);
			tokens = tokens->next;
		}
		free(input);
	}
	return (0);
}
