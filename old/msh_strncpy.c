/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   msh_strncpy.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jho <jho@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 12:08:58 by jho               #+#    #+#             */
/*   Updated: 2023/10/10 12:09:21 by jho              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

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
