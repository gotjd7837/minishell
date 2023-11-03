/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   msh_split.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haekang <haekang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/03 16:22:14 by haekang           #+#    #+#             */
/*   Updated: 2023/11/03 17:09:18 by haekang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/msh_util.h"

static char	*msh_result_malloc(char *str, char c, char **result, int idx)
{
	int	len;

	len = 0;
	while (str[len] && str[len] != c)
		len++;
	result[idx] = (char *)malloc(sizeof(char) * (len + 1));
	if (result[idx] == NULL)
	{
		while (--idx >= 0)
			free(result[idx]);
		free(result);
		return (NULL);
	}
	msh_strlcpy(result[idx], str, len + 1);
	return (result[idx]);
}

static char	**msh_result_double_malloc(char *str, char c)
{
	size_t	cnt;
	char	**result;

	cnt = 0;
	while (*str)
	{
		if (*str != c)
		{
			cnt++;
			while (*str && *str != c)
				str++;
		}
		else
			str++;
	}
	result = (char **)malloc(sizeof(char *) * (cnt + 1));
	if (result == NULL)
		return (NULL);
	return (result);
}

char	**msh_split(char *s, char c)
{
	char	*str;
	char	**result;
	int		i;

	str = (char *)s;
	i = 0;
	if (s == NULL)
		return (NULL);
	result = msh_result_double_malloc(str, c);
	if (result == NULL)
		return (NULL);
	while (*str)
	{
		if (*str != c)
		{
			if (msh_result_malloc(str, c, result, i++) == NULL)
				return (NULL);
			while (*str && *str != c)
				str++;
		}
		else
			str++;
	}
	result[i] = NULL;
	return (result);
}
