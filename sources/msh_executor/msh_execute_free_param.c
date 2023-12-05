/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   msh_execute_free_param.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haekang <haekang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 12:50:41 by jho               #+#    #+#             */
/*   Updated: 2023/12/05 19:34:14 by haekang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/msh.h"

void	msh_execute_free_param(char **params)
{
	int	index;

	if (params == NULL)
		return ;
	index = 0;
	while (*(params + index) != NULL)
	{
		free(*(params + index));
		++index;
	}
	free(params);
}
