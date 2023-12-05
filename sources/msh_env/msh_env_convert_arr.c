/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   msh_env_convert_arr.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haekang <haekang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 13:42:23 by haekang           #+#    #+#             */
/*   Updated: 2023/12/05 20:03:32 by haekang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/msh.h"

static char	*msh_malloc_key_value(t_env *env)
{
	char	*arr;
	char	*tmp;

	tmp = msh_strjoin(env->key, "=");
	if (tmp == NULL)
		return (NULL);
	arr = msh_strjoin(tmp, env->value);
	if (arr == NULL)
		return (NULL);
	free(tmp);
	return (arr);
}

static int	msh_env_listlen(t_env *env)
{
	int	len;

	len = 0;
	while (env != NULL)
	{
		if (env->value != NULL)
			len++;
		env = env->next;
	}
	return (len);
}

char	**msh_env_convert_arr(t_env *env)
{
	int		i;
	int		len;
	char	**arr;

	i = 0;
	len = msh_env_listlen(env);
	arr = malloc(sizeof(char *) * (len + 1));
	if (arr == NULL)
		return (NULL);
	while (env != NULL)
	{
		if (env->value != NULL)
			arr[i++] = msh_malloc_key_value(env);
		env = env->next;
	}
	arr[i] = NULL;
	return (arr);
}
