/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   msh_substr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haekang <haekang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/29 20:30:58 by jho               #+#    #+#             */
/*   Updated: 2023/10/26 12:34:26 by jho              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char	*msh_substr(char *str, int begin, int end)
{
	int		index;
	char	*substr;

	index = 0;
	substr = malloc(sizeof(char) * (end - begin + 1));
	if (substr == NULL)
		return (NULL);
	while (begin < end)
	{
		*(substr + index) = *(str + begin);
		++index;
		++begin;
	}
	substr[index] = '\0';
	return (substr);
}
