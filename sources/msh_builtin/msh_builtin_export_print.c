/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   msh_builtin_export_print.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haekang <haekang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 18:10:18 by haekang           #+#    #+#             */
/*   Updated: 2023/11/25 01:06:32 by haekang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/msh_builtin.h"

int	msh_export_print(t_env *env)
{
	t_env	*node;

	node = env;
	while (node != NULL)
	{
		if (node->value == NULL)
			printf("declare -x %s\n", node->key);
		else if (!msh_strcmp(node->key, "_"))
		{
			node = node->next;
			continue ;
		}
		else
			printf("declare -x %s=\"%s\"\n", node->key, node->value);
		node = node->next;
	}
	return (1);
}
