/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   msh_comp_add_node.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jho <jho@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/12 18:03:17 by jho               #+#    #+#             */
/*   Updated: 2023/10/12 18:17:21 by jho              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/minishell.h"

int	msh_comp_add_node(t_comp **origin, char *input, int begin, int end)
{
	char	*value;
	t_comp	*node;

	value = malloc(end - begin + 1);
	if (value == NULL)
		return (0);
	msh_strncpy(value, input + begin, end - begin);
	*(value + end - begin) = '\0';
	node = malloc(sizeof(t_comp));
	if (node == NULL)
	{
		free(value);
		return (0);
	}
	node->value = value;
	node->next = 0;
	if (*origin == NULL)
		*origin = node;
	else
		(msh_comp_last_node(*origin))->next = node;
	return (1);
}
