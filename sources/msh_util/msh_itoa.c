/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   msh_itoa.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haekang <haekang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/25 09:50:41 by haekang           #+#    #+#             */
/*   Updated: 2023/11/25 09:52:43 by haekang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/msh_util.h"

static char	*msh_result_malloc(long value, size_t *len, unsigned char *neg_flag)
{
	unsigned char	cnt;
	char			*result;

	cnt = 0;
	if (value < 0)
	{
		*neg_flag = 1;
		value = (-1) * value;
	}
	if (value > 0)
	{
		while (value)
		{
			cnt++;
			value /= 10;
		}
	}
	else if (value == 0)
		cnt = 1;
	result = (char *)malloc(sizeof(char) * (cnt + *neg_flag + 1));
	if (result == NULL)
		return (NULL);
	result[cnt + *neg_flag] = '\0';
	*len = cnt + *neg_flag;
	return (result);
}

char	*msh_itoa(int n)
{
	long			value;
	size_t			len;
	unsigned char	neg_flag;
	char			*result;

	value = (long)n;
	neg_flag = 0;
	result = msh_result_malloc(value, &len, &neg_flag);
	if (result == NULL)
		return (NULL);
	if (value < 0)
		value = (-1) * value;
	if (value > 0)
	{
		if (neg_flag == 1)
			result[0] = '-';
		while (value)
		{
			result[(len--) - 1] = (value % 10) + '0';
			value /= 10;
		}
	}
	else if (value == 0)
		result[len - 1] = '0';
	return (result);
}
