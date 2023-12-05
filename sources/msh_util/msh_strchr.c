/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   msh_strchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haekang <haekang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/27 20:08:47 by jho               #+#    #+#             */
/*   Updated: 2023/12/05 19:40:00 by haekang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/msh.h"

char	*msh_strchr(char *s, int c)
{
	size_t	index;
	size_t	len;

	index = 0;
	len = msh_strlen(s);
	while (index <= len)
	{
		if (*(s + index) == (char)c)
			return ((char *)(s + index));
		++index;
	}
	return (NULL);
}
