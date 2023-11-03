/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   msh_strchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jho <jho@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/27 20:08:47 by jho               #+#    #+#             */
/*   Updated: 2023/10/27 20:09:11 by jho              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/msh_util.h"

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
