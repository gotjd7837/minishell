/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   msh_parse_command.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haeseong <haeseong@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 04:30:07 by haeseong          #+#    #+#             */
/*   Updated: 2023/10/24 04:44:40 by haeseong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int	msh_parse_command(t_token **tokens, t_tree *parent)
{
	t_tree	*node;

	if (msh_accept(tokens, WORD) || msh_accept(tokens, ASSIGNMENT_WORD)
		|| msh_accept(tokens, REDIRECTION))
	{
		node = msh_parse_new_node(SIMPLE_COMMAND);
		if (node == NULL)
			return (0);
		msh_parse_add_child(parent, node);
		if (!msh_parse_simple_command(tokens, node))
			return (0);
	}
	else if (msh_accept(tokens, L_BRACKET))
	{
		node = msh_parse_new_node(SUBSHELL);
		if (node == NULL)
			return (0);
		msh_parse_add_child(parent, node);
		if (!msh_parse_subshell(tokens, node))
			return (0);
	}
	else
		//error
	return (1);
}
