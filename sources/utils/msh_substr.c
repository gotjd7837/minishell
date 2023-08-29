/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   msh_substr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jho <jho@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/29 20:30:58 by jho               #+#    #+#             */
/*   Updated: 2023/08/29 21:13:55 by jho              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

char	*msh_substr(char *s, int start_idx, int end_idx)
{
	char	*substr;

	substr = malloc(sizeof(char) * end_idx - start_idx + 1);
	if (substr == 0)
		return (0);
	while (start_idx < end_idx)
	{
		substr[start_idx] = s[start_idx];
		++start_idx;
	}
	substr[start_idx] = '\0';
	return (substr);
}
