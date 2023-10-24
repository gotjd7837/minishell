/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   msh_parse_simple_command_element.c                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jho <jho@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 13:29:05 by jho               #+#    #+#             */
/*   Updated: 2023/10/24 14:18:05 by jho              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int	msh_parse_simple_command_element(t_token *root, t_token **tokens)
{
	t_token	*token;

	token = msh_dequeue(tokens);
	token->next = NULL;
	token->child = NULL;
	msh_add_child(root, token);
	return (1);
}
