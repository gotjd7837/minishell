/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   msh_main.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haeseong <haeseong@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/12 12:03:25 by jho               #+#    #+#             */
/*   Updated: 2023/10/24 16:45:53 by jho              ###   ########.fr       */
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

void	msh_print_symbol(t_token *token)
{
	if (token->symbol == WORD)
		printf("%s", "WORD");
	else if (token->symbol == ASSIGNMENT_WORD)
		printf("%s", "ASSIGNMENT_WORD");
	else if (token->symbol == REDIRECTION)
		printf("%s", "REDIRECTION");
	else if (token->symbol == PIPE)
		printf("%s", "PIPE");
	else if (token->symbol == AND_IF)
		printf("%s", "AND_IF");
	else if (token->symbol == OR_IF)
		printf("%s", "OR_IF");
	else if (token->symbol == L_BRACKET)
		printf("%s", "L_BRACKET");
	else if (token->symbol == R_BRACKET)
		printf("%s", "R_BRACKET");
	else if (token->symbol == EQUAL_SIGN)
		printf("%s", "EQUAL_SIGN");
	else if (token->symbol == ROOT)
		printf("%s", "ROOT");
	else if (token->symbol == LIST)
		printf("%s", "LIST");
	else if (token->symbol == SUBSHELL)
		printf("%s", "SUBSHELL");
	else if (token->symbol == PIPELINE)
		printf("%s", "PIPELINE");
	else if (token->symbol == COMMAND)
		printf("%s", "COMMAND");
	else if (token->symbol == SIMPLE_COMMAND)
		printf("%s", "SIMPLE_COMMAND");
	else if (token->symbol == SIMPLE_COMMAND_ELEMENT)
		printf("%s", "SIMPLE_COMMAND_ELEMENT");
	if (token->value != NULL)
	{
		printf(" (%s)", token->value);
	}
	printf("\n");
}

void	msh_print_tree(t_token *tree, int depth)
{
	if (tree == NULL)
		return ;
	for (int idx = 0; idx < depth; idx++)
		printf("\t");
	msh_print_symbol(tree);
	tree = tree->child;
	while (tree != NULL)
	{
		msh_print_tree(tree, depth + 1);
		tree = tree->next;
	}
}


int	main(int argc, char *argv[], char *envp[])
{
	t_env	*env;
	char	*input;
	t_token	*tokens;
	t_token	*tree;

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
		printf("[Symbol table]\n");
		msh_print_tokens(tokens);
		tree = msh_parse(&tokens);
		printf("\n\n");
		printf("[Parse tree]\n");
		if (tree != NULL)
			msh_print_tree(tree, 0);
		else
			printf("Parse error\n");
		msh_free_tokens(tokens);
		free(input);
		system("leaks minishell");
	}
	msh_env_free_list(env);
	return (0);
}
