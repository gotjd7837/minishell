/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   msh_main.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jho <jho@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/25 16:14:20 by jho               #+#    #+#             */
/*   Updated: 2023/09/12 17:03:12 by jho              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	msh_print_tokens(t_token *tokens)
{
	while (tokens != 0)
	{
		if (tokens->symbol == WORD)
			printf("%-18s%-15s\n", "WORD", tokens->value);
		else if (tokens->symbol == ASSIGNMENT_WORD)
			printf("%-18s%-15s\n", "ASSIGNMENT_WORD", tokens->value);
		else if (tokens->symbol == REDIRECTION)
			printf("%-18s%-15s\n", "REDIRECTION", tokens->value);
		else if (tokens->symbol == PIPE)
			printf("%-18s%-15s\n", "PIPE", tokens->value);
		else if (tokens->symbol == AND_IF)
			printf("%-18s%-15s\n", "AND_IF", tokens->value);
		else if (tokens->symbol == OR_IF)
			printf("%-18s%-15s\n", "OR_IF", tokens->value);
		else if (tokens->symbol == L_BRACKET)
			printf("%-18s%-15s\n", "L_BRACKET", tokens->value);
		else if (tokens->symbol == R_BRACKET)
			printf("%-18s%-15s\n", "R_BRACKET", tokens->value);
		else if (tokens->symbol == EQUAL_SIGN)
			printf("%-18s%-15s\n", "EQUAL_SIGN", tokens->value);
		tokens = tokens->next;
	}
}

int	main(void)
{
	char	*input;
	t_token	*tokens;

	while (1)
	{
		input = readline("minishell$ ");
		tokens = msh_lexical_analysis(input);
		msh_print_tokens(tokens);
		free(input);
	}
	return (0);
}
