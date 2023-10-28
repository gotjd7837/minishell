/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   msh_main.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haeseong <haeseong@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/12 12:03:25 by jho               #+#    #+#             */
/*   Updated: 2023/10/28 08:33:48 by jho              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/msh.h"


void	msh_print_tokens(t_token *tokens)
{
	while (tokens != 0)
	{
		if (tokens->sym == WORD)
			printf("%-18s%-15s\n", "WORD", tokens->val);
		else if (tokens->sym == ASSIGN_WORD)
			printf("%-18s%-15s\n", "ASSIGNMENT_WORD", tokens->val);
		else if (tokens->sym == REDIR)
			printf("%-18s%-15s\n", "REDIR", tokens->val);
		else if (tokens->sym == PIPE)
			printf("%-18s%-15s\n", "PIPE", tokens->val);
		else if (tokens->sym == AND_IF)
			printf("%-18s%-15s\n", "AND_IF", tokens->val);
		else if (tokens->sym == OR_IF)
			printf("%-18s%-15s\n", "OR_IF", tokens->val);
		else if (tokens->sym == L_BRA)
			printf("%-18s%-15s\n", "L_BRA", tokens->val);
		else if (tokens->sym == R_BRA)
			printf("%-18s%-15s\n", "R_BRA", tokens->val);
		tokens = tokens->next;
	}
}
/*
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
*/


int	main(int argc, char *argv[], char *envp[])
{
	char	*input;
	t_env	*env;
	char	*expanded;
	t_token	*sym_table;

	(void) argc;
	(void) argv;
	env = msh_env_new_list(envp);
	while (1)
	{
		input = readline("msh$> ");
		expanded = msh_expand(input, env);
		printf("%s\n", expanded);
		sym_table = msh_lex(expanded);
		if (sym_table == NULL)
		{
			printf("Lex error\n");
		}
		else
			msh_print_tokens(sym_table);
		msh_token_free_list(sym_table);
		free(expanded);
		free(input);
		system("leaks minishell | grep leaked");
	}
	return (0);
}
