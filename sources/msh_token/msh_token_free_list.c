/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   msh_token_free_list.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haekang <haekang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 08:54:21 by jho               #+#    #+#             */
/*   Updated: 2023/12/05 19:38:34 by haekang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/msh.h"

t_token	*msh_token_free_list(t_token *list)
{
	t_token	*next;

	if (list == NULL)
		return (NULL);
	while (list != NULL)
	{
		next = list->next;
		msh_token_free(list);
		list = next;
	}
	return (NULL);
}
