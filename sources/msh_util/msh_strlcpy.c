/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   msh_strlcpy.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haekang <haekang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/03 16:27:02 by haekang           #+#    #+#             */
/*   Updated: 2023/12/05 19:40:25 by haekang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/msh.h"

size_t	msh_strlcpy(char *dst, char *src, size_t dstsize)
{
	size_t	i;

	i = 0;
	if (dstsize == 0)
		return (msh_strlen(src));
	while (src[i] && (i + 1 < dstsize))
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return (msh_strlen(src));
}
