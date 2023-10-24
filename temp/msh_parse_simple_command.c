/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   msh_parse_simple_command.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haeseong <haeseong@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 05:11:23 by haeseong          #+#    #+#             */
/*   Updated: 2023/10/24 05:19:26 by haeseong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int	msh_parse_simple_command(t_token **tokens, t_tree *parent)
{
	t_tree	*node;

	while (1)
	{
		if (msh_accept(tokens, WORD) || msh_accept(tokens, ASSIGNMENT_WORD)
			|| msh_accept(tokens, REDIRECTION))
		{
			node = msh_parse_new_node(SIMPLE_COMMAND_ELEMENT);
			if (node == NULL)
				return (0);
			msh_parse_add_child(parent, node);
			if (!msh_parse_simple_command_element(tokens, node))
				return (0);
		}
		else
			break ;
	}
	return (1);
}
