/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   msh_env_free_node.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haekang <haekang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/12 16:08:59 by jho               #+#    #+#             */
/*   Updated: 2023/12/05 19:33:31 by haekang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/msh.h"

t_env	*msh_env_free_node(t_env *node)
{
	if (node->key != NULL)
		free(node->key);
	if (node->value != NULL)
		free(node->value);
	free(node);
	return (NULL);
}
