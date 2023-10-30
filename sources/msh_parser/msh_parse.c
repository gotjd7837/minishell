/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   msh_parse.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jho <jho@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 16:40:09 by jho               #+#    #+#             */
/*   Updated: 2023/10/30 18:46:17 by jho              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/msh_parser.h"
#include <stdio.h>

int	msh_parse_list(t_token **parse_tree, t_token **sym_table);

int	msh_parse_simple_cmd(t_token **parse_tree, t_token **sym_table)
{
	t_token	*parent;
	t_token	*child;

	parent = msh_token_malloc_sym(SIMPLE_CMD);
	if (parent == NULL)
		return (0);
	msh_token_add_child(parse_tree, parent);

	while (msh_accept(*sym_table, WORD) || msh_accept(*sym_table, ASSIGN_WORD)
		|| msh_accept(*sym_table, REDIR))
	{
		child = msh_token_dequeue(sym_table);
		if (child == NULL)
			return (0);
		msh_token_add_child(&parent, child);
	}
	return (1);
}

int	msh_parse_subshell(t_token **parse_tree, t_token **sym_table)
{
	t_token	*parent;

	parent = msh_token_malloc_sym(SUBSHELL);
	if (parent == NULL)
		return (0);
	msh_token_add_child(parse_tree, parent);
	if (msh_accept(*sym_table, L_BRA))
		msh_token_remove_front(sym_table);
	else
		return (0);
	if (!msh_parse_list(&parent, sym_table))
		return (0);
	if (msh_accept(*sym_table, R_BRA))
		msh_token_remove_front(sym_table);
	else
		return (0);
	return (1);
}

int	msh_parse_redir_list(t_token **parse_tree, t_token **sym_table)
{
	t_token	*parent;
	t_token	*child;

	parent = msh_token_malloc_sym(REDIR_LIST);
	if (parent == NULL)
		return (0);
	msh_token_add_child(parse_tree, parent);
	while (msh_accept(*sym_table, REDIR))
	{
		child = msh_token_dequeue(sym_table);
		if (child == NULL)
			return (0);
		msh_token_add_child(&parent, child);
	}
	return (1);
}

int	msh_parse_cmd(t_token **parse_tree, t_token **sym_table)
{
	t_token	*parent;

	parent = msh_token_malloc_sym(CMD);
	if (parent == NULL)
		return (0);
	msh_token_add_child(parse_tree, parent);
	if (msh_accept(*sym_table, WORD) || msh_accept(*sym_table, ASSIGN_WORD)
		|| msh_accept(*sym_table, REDIR))
	{
		if (!msh_parse_simple_cmd(&parent, sym_table))
			return (0);
	}
	else if (msh_accept(*sym_table, L_BRA))
	{
		if (!msh_parse_subshell(&parent, sym_table))
			return (0);
		if (msh_accept(*sym_table, REDIR)
			&& !msh_parse_redir_list(&parent, sym_table))
			return (0);
	}
	else
		return (0);
	return (1);
}

int	msh_parse_pipeline(t_token **parse_tree, t_token **sym_table)
{
	t_token	*parent;
	t_token	*child;

	parent = msh_token_malloc_sym(PIPELINE);
	if (parent == NULL)
		return (0);
	msh_token_add_child(parse_tree, parent);
	if (!msh_parse_cmd(&parent, sym_table))
		return (0);
	if (msh_accept(*sym_table, PIPE))
	{
		child = msh_token_dequeue(sym_table);
		if (child == NULL)
			return (0);
		msh_token_add_child(parse_tree, child);
		if (!msh_parse_pipeline(parse_tree, sym_table))
			return (0);
	}
	return (1);
}

int	msh_parse_list(t_token **parse_tree, t_token **sym_table)
{
	t_token	*parent;
	t_token	*child;

	parent = msh_token_malloc_sym(LIST);
	if (parent == NULL)
		return (0);
	msh_token_add_child(parse_tree, parent);
	if (!msh_parse_pipeline(&parent, sym_table))
		return (0);
	if (msh_accept(*sym_table, AND_IF) || msh_accept(*sym_table, OR_IF))
	{
		child = msh_token_dequeue(sym_table);
		if (child == NULL)
			return (0);
		msh_token_add_child(&parent, child);
		if (!msh_parse_list(&parent, sym_table))
			return (0);
	}
	return (1);
}

t_token	*msh_parse(t_token *sym_table)
{
	t_token	*parse_tree;

	parse_tree = msh_token_malloc_sym(ROOT);
	if (parse_tree == NULL)
		return (NULL);
	while (msh_accept(sym_table, WORD) || msh_accept(sym_table, ASSIGN_WORD)
		|| msh_accept(sym_table, REDIR) || msh_accept(sym_table, L_BRA))
	{
		if (!msh_parse_list(&parse_tree, &sym_table))
			return (msh_token_free_tree(parse_tree));
	}
	if (sym_table == NULL)
		return (parse_tree);
	return (NULL);
}
