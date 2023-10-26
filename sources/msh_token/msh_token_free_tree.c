/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   msh_token_free_tree.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jho <jho@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 09:00:42 by jho               #+#    #+#             */
/*   Updated: 2023/10/26 09:06:08 by jho              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "msh_token.h"

void	msh_token_free_tree(t_token *root)
{
	t_token	*child;
	t_token	*next_child;

	if (root == NULL)
		return ;
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
}
