/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   msh_env_parse_value.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haekang <haekang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/12 16:07:58 by jho               #+#    #+#             */
/*   Updated: 2023/12/05 19:33:54 by haekang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/msh.h"

char	*msh_env_parse_value(char *envp)
{
	int		index;
	size_t	len;
	char	*value;

	index = 0;
	if (!msh_strchr(envp, '='))
		return (NULL);
	while (*(envp + index) != '=')
		++index;
	++index;
	len = msh_strlen(envp + index);
	value = malloc(len + 1);
	if (value == NULL)
		return (NULL);
	msh_strncpy(value, envp + index, len);
	return (value);
}
