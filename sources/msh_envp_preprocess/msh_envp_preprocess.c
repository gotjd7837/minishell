/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   msh_envp_preprocess.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haekang <haekang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 17:40:07 by haekang           #+#    #+#             */
/*   Updated: 2023/10/10 17:50:38 by haekang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

static char	*msh_get_value(char *str)
{
	int		end_idx;
	int		equal_idx;
	char	*value;

	end_idx = 0;
	equal_idx = 0;
	while (str[end_idx])
	{
		if (str[end_idx] == '=')
			equal_idx = end_idx;
		end_idx++;
	}
	value = msh_substr(str, (equal_idx + 1), end_idx);
	if (value == NULL)
		return (NULL);
	return (value);
}

static char	*msh_get_key(char *str)
{
	int		i;
	int		equal_idx;
	char	*key;

	i = 0;
	equal_idx = 0;
	while (str[equal_idx])
	{
		if (str[equal_idx] == '=')
			break ;
		equal_idx++;
	}
	key = msh_substr(str, 0, equal_idx);
	if (key == NULL)
		return (NULL);
	return (key);
}

static void	msh_env_lstadd(t_env **envp_list, char *str)
{
	t_env	*node;
	char	*key;
	char	*value;

	node = *envp_list;
	key = msh_get_key(str);
	value = msh_get_value(str);
	while (node->next != NULL)
		node = node->next;
	node->next = msh_new_env_node(key, value);
	node->next->prev = node;
}

int	msh_envp_preprocess(char **envp, t_env **envp_list)
{
	int		i;
	char	*key;
	char	*value;

	i = 0;
	while (envp[i] != NULL)
	{
		if (i == 0)
		{
			key = msh_get_key(envp[i]);
			value = msh_get_value(envp[i]);
			*envp_list = msh_new_env_node(key, value);
		}
		else
			msh_env_lstadd(envp_list, envp[i]);
		i++;
	}
	return (0);
}
