/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   msh_find_env_path.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haekang <haekang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/03 17:19:27 by haekang           #+#    #+#             */
/*   Updated: 2023/11/03 17:20:59 by haekang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/msh_pathfinder.h"

char	**msh_find_env_path(t_env *env)
{
	char	**res;
	char	*path;

	path = msh_env_get_value(env, "PATH");
	if (*path == '\0')
	{
		free(path);
		return (NULL);
	}
	res = msh_split(path, ':');
	if (res == NULL)
		return (NULL);
	return (res);
}
