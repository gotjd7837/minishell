/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   msh_env_parse_key.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haekang <haekang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/12 16:07:28 by jho               #+#    #+#             */
/*   Updated: 2023/12/05 19:33:50 by haekang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/msh.h"

char	*msh_env_parse_key(char *envp)
{
	int		index;
	char	*key;

	index = 0;
	if (!msh_strchr(envp, '='))
		return (NULL);
	while (*(envp + index) != '=')
		++index;
	key = malloc(index + 1);
	if (key == NULL)
		return (NULL);
	msh_strncpy(key, envp, index);
	return (key);
}
