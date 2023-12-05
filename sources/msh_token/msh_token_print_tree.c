/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   msh_token_print_tree.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haekang <haekang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 17:55:04 by jho               #+#    #+#             */
/*   Updated: 2023/12/05 20:06:35 by haekang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/msh.h"

void	msh_token_print_sym_2(t_token *token)
{
	if (token->sym == R_BRA)
		printf("%-12s", "R_BRA");
	else if (token->sym == REDIR_LIST)
		printf("%-12s", "REDIR_LIST");
	else if (token->sym == SIMPLE_CMD)
		printf("%-12s", "SIMPLE_CMD");
	else if (token->sym == CMD)
		printf("%-12s", "CMD");
	else if (token->sym == PIPELINE)
		printf("%-12s", "PIPELINE");
	else if (token->sym == LIST)
		printf("%-12s", "LIST");
	else if (token->sym == SUBSHELL)
		printf("%-12s", "SUBSHELL");
	else if (token->sym == ROOT)
		printf("%-12s", "ROOT");
}

void	msh_token_print_sym(t_token *token)
{
	if (token->sym == WORD)
		printf("%-12s", "WORD");
	else if (token->sym == ASSIGN_WORD)
		printf("%-12s", "ASSIGN_WORD");
	else if (token->sym == REDIR)
		printf("%-12s", "REDIR");
	else if (token->sym == PIPE)
		printf("%-12s", "PIPE");
	else if (token->sym == AND_IF)
		printf("%-12s", "AND_IF");
	else if (token->sym == OR_IF)
		printf("%-12s", "OR_IF");
	else if (token->sym == L_BRA)
		printf("%-12s", "L_BRA");
	msh_token_print_sym_2(token);
}

void	msh_token_print_val(t_token *token)
{
	if (token->val == NULL)
		return ;
	printf(" (%s)", token->val);
}

void	msh_token_print_tree(t_token *tree, int depth)
{
	int		idx;
	t_token	*child;

	if (tree == NULL)
		return ;
	idx = -1;
	while (++idx < depth)
		printf("\t");
	msh_token_print_sym(tree);
	msh_token_print_val(tree);
	printf("\n");
	child = tree->child;
	while (child != NULL)
	{
		msh_token_print_tree(child, depth + 1);
		child = child->next;
	}
}
