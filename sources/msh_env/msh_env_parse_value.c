/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   msh_env_parse_value.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jho <jho@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/12 16:07:58 by jho               #+#    #+#             */
/*   Updated: 2023/10/27 20:02:38 by jho              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/msh_env.h"

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
