/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   msh_main.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jho <jho@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/25 16:14:20 by jho               #+#    #+#             */
/*   Updated: 2023/10/10 14:07:41 by jho              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int	main(void)
{
	char	*input;
	t_token	*tokens;

	while (1)
	{
		input = readline("msh$> ");
		tokens = msh_lexical_analysis(input);
		free(input);
	}
	return (0);
}
