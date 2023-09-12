/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   msh_parse.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jho <jho@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/29 22:32:39 by jho               #+#    #+#             */
/*   Updated: 2023/08/29 22:50:04 by jho              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

t_tree	*msh_parse(t_token	*tokens)
{
	t_tree	*tree;
	t_token	next_token;

	tree = 0;
	next_token = *tokens;
	return (tree);
}
