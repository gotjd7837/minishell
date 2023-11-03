/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   msh_strjoin.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haekang <haekang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/03 16:59:25 by haekang           #+#    #+#             */
/*   Updated: 2023/11/03 17:12:33 by haekang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/msh_util.h"

static char	*msh_str_cpy(char *s1, char *s2, char *arr)
{
	int	i;
	int	j;

	i = 0;
	while (s1[i])
	{
		arr[i] = s1[i];
		i++;
	}
	j = 0;
	while (s2[j])
	{
		arr[i + j] = s2[j];
		j++;
	}
	arr[i + j] = '\0';
	return (arr);
}

char	*msh_strjoin(char *s1, char *s2)
{
	size_t	i;
	size_t	j;
	char	*arr;

	i = msh_strlen(s1);
	j = msh_strlen(s2);
	arr = (char *)malloc(sizeof(char) * (i + j + 1));
	if (arr == NULL)
		return (NULL);
	msh_str_cpy(s1, s2, arr);
	return (arr);
}
