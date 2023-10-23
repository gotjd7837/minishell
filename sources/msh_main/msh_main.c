/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   msh_main.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haeseong <haeseong@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/12 12:03:25 by jho               #+#    #+#             */
/*   Updated: 2023/10/23 20:45:16 by haeseong         ###   ########.fr       */
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

int	main(int argc, char *argv[], char *envp[])
{
	t_env	*env;
	char	*input;
	t_token	*tokens;
	t_tree	*tree;

	(void) argc;
	(void) argv;
	env = msh_env_new_list(envp);
	if (env == NULL)
	{
		write(2, "msh : failed to read environment.\n", 34);
		return (1);
	}
	while (1)
	{
		input = readline("msh$> ");
		tokens = msh_lexical_analysis(input, env);
		tree = msh_create_parse_tree(&tokens);
		msh_print_tokens(tokens);
		msh_free_tokens(tokens);
		free(input);
		system("leaks minishell");
	}
	msh_env_free_list(env);
	return (0);
}
