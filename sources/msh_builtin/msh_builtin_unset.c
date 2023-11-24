/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   msh_builtin_unset.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haekang <haekang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 20:27:11 by haekang           #+#    #+#             */
/*   Updated: 2023/11/25 01:10:54 by haekang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/msh_builtin.h"

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

int	msh_builtin_unset(int in, int out, char **cmd, t_env *env)
{
	t_env	*node;
	char	*key;

	(void)in;
	(void)out;
	(void)env;
	node = env;
	key = cmd[1];
	if (!((key[0] >= 'a' && key[0] <= 'z')
			|| (key[0] >= 'A' && key[0] <= 'Z') || (key[0] == '_')))
	{
		printf("minishell: unset: '%s': not a valid identifier\n", key);
		g_exit_status = 1;
		return (1);
	}
	while (node != NULL)
	{
		if (msh_strcmp(node->key, key) == 0)
			msh_del_node(node);
		node = node->next;
	}
	return (0);
}
//명령어 반환값 처리 해줘야함