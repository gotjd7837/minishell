/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   msh_env_new_node.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jho <jho@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/12 16:08:26 by jho               #+#    #+#             */
/*   Updated: 2023/10/17 12:44:23 by jho              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int	msh_env_new_node(t_env **node)
{
	*node = malloc(sizeof(t_env));
	if (*node == NULL)
		return (0);
	(*node)->key = NULL;
	(*node)->value = NULL;
	(*node)->prev = NULL;
	(*node)->next = NULL;
	return (1);
}
