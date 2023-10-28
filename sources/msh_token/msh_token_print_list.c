/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   msh_token_print_list.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jho <jho@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 11:40:12 by jho               #+#    #+#             */
/*   Updated: 2023/10/27 21:09:30 by jho              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/msh_token.h"
#include <stdio.h>

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
