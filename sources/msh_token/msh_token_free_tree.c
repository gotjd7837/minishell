/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   msh_token_free_tree.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haekang <haekang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 09:00:42 by jho               #+#    #+#             */
/*   Updated: 2023/12/05 19:38:37 by haekang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/msh.h"

t_token	*msh_token_free_tree(t_token *root)
{
	t_token	*child;
	t_token	*next_child;

	if (root == NULL)
		return (NULL);
	if (root->child != NULL)
	{
		child = root->child;
		while (child != NULL)
		{
			next_child = child->next;
			msh_token_free_tree(child);
			child = next_child;
		}
	}
	if (root->val != NULL)
		free(root->val);
	free(root);
	return (NULL);
}
