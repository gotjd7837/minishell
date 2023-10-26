/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   msh_count_equal_sign.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haekang <haekang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/12 16:42:39 by jho               #+#    #+#             */
/*   Updated: 2023/10/20 15:15:01 by haekang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/minishell.h"

int	msh_count_equal_sign(char *s)
{
	int	index;
	int	count;

	index = 0;
	count = 0;
	while (*(s + index) != '\0')
	{
		if (*(s + index) == '=')
			++count;
		++index;
	}
	return (count);
}
