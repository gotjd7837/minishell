/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   msh_substr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haekang <haekang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/29 20:30:58 by jho               #+#    #+#             */
/*   Updated: 2023/10/10 18:03:58 by haekang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

char	*msh_substr(char *s, int start_idx, int end_idx)
{
	int		i;
	char	*substr;

	i = 0;
	substr = malloc(sizeof(char) * (end_idx - start_idx + 1));
	if (substr == 0)
		return (0);
	while (start_idx < end_idx)
	{
		substr[i] = s[start_idx];
		++i;
		++start_idx;
	}
	substr[i] = '\0';
	return (substr);
}
