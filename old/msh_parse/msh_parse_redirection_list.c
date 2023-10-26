/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   msh_parse_redirection_list.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jho <jho@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 16:06:32 by jho               #+#    #+#             */
/*   Updated: 2023/10/24 16:07:43 by jho              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int	msh_parse_redirection_list(t_token *root, t_token **tokens)
{
	t_token	*token;

	while (msh_accept(REDIRECTION, *tokens))
	{
		token = msh_dequeue(tokens);
		msh_add_child(root, token);
	}
	return (1);
}
