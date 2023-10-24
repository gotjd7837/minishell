/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   msh_parse_list.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jho <jho@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 12:54:39 by jho               #+#    #+#             */
/*   Updated: 2023/10/24 14:21:47 by jho              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int	msh_parse_list(t_token *root, t_token **tokens)
{
	t_token	*token;

	token = msh_new_token_by_sym(PIPELINE);
	if (token == NULL)
		return (0);
	msh_add_child(root, token);
	msh_parse_pipeline(token, tokens);
	return (1);
}
