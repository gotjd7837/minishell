/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   msh_strncpy.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haekang <haekang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/27 20:16:06 by jho               #+#    #+#             */
/*   Updated: 2023/12/05 19:40:31 by haekang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/msh.h"

char	*msh_strncpy(char *dest, char *src, size_t n)
{
	size_t	index;

	index = 0;
	while (*(src + index) != '\0' && index < n)
	{
		*(dest + index) = *(src + index);
		++index;
	}
	*(dest + index) = '\0';
	return (dest);
}
