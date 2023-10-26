/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   msh_token_free_list.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jho <jho@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 08:54:21 by jho               #+#    #+#             */
/*   Updated: 2023/10/26 12:07:41 by jho              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/msh_token.h"

void	msh_token_free_list(t_token *list)
{
	t_token	*next;

	if (list == NULL)
		return ;
	while (list != NULL)
	{
		next = list->next;
		msh_token_free(token);
		list = next;
	}
}
