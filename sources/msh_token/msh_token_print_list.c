/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   msh_token_print_list.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haekang <haekang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 11:40:12 by jho               #+#    #+#             */
/*   Updated: 2023/12/05 19:39:08 by haekang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/msh.h"

void	msh_token_print_list(t_token *list)
{
	printf("Token list : ");
	while (list != NULL)
	{
		printf("%s -> ", list->val);
		list = list->next;
	}
	printf("NULL\n");
}
