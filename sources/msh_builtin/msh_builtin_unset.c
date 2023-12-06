/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   msh_builtin_unset.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haekang <haekang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 20:27:11 by haekang           #+#    #+#             */
/*   Updated: 2023/12/06 16:23:32 by haekang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/msh.h"

static void	msh_del_node(t_env *node)
{
	t_env	*tmp;

	free(node->key);
	free(node->value);
	if (node->prev == NULL)
	{
		node->key = node->next->key;
		node->value = node->next->value;
		tmp = node->next;
		node->next = node->next->next;
		free(tmp);
	}
	else if (node->next == NULL)
	{
		node->prev->next = NULL;
		free(node);
	}
	else
	{
		node->next->prev = node->prev;
		node->prev->next = node->next;
		free(node);
	}
}

static int	msh_unset_search_env(t_env *env, char *key)
{
	while (env != NULL)
	{
		if (msh_strcmp(env->key, key) == 0)
		{
			msh_del_node(env);
			return (1);
		}
		env = env->next;
	}
	return (0);
}

static int	msh_unset_check_key(char *key, int pipe)
{
	int	i;

	i = 0;
	while (key[i] != '\0')
	{
		if ((key[i] >= 'a' && key[i] <= 'z')
			|| (key[i] >= 'A' && key[i] <= 'Z')
			|| (key[i] >= '0' && key[i] <= '9')
			|| (key[i] == '_'))
			i++;
		else
		{
			write(2, "minishell: unset: '", 19);
			write(2, key, msh_strlen(key));
			write(2, "': not a valid identifier\n", 26);
			g_exit_status = 1;
			if (pipe == 1)
				exit (g_exit_status);
			return (0);
		}
	}
	return (1);
}

int	msh_builtin_unset(int *fd, int pipe, char **cmd, t_env *env)
{
	char	**key;
	int		i;

	(void)fd;
	(void)env;
	g_exit_status = 0;
	key = cmd;
	i = 1;
	while (key[i] != NULL)
		msh_unset_check_key(key[i++], pipe);
	i = 1;
	while (key[i] != NULL)
		msh_unset_search_env(env, key[i++]);
	if (pipe == 1)
		exit (g_exit_status);
	return (0);
}
