/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   msh_export.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haekang <haekang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/27 21:49:34 by haekang           #+#    #+#             */
/*   Updated: 2023/11/03 20:01:32 by haekang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/msh_builtin.h"

static int	msh_env_key_exist(t_env *env, char *key)
{
	while (env != NULL)
	{
		if (!msh_strcmp(key, env->key))
			return (1);
		env = env->next;
	}
	return (0);
}

static int	msh_export_add_node(t_env *env, char *cmd_arg)
{
	t_env	*node;
	char	*key;

	key = msh_env_parse_key(cmd_arg);
	if (key == NULL)
		return (0);
	if (msh_env_key_exist(env, key) == 1)
	{
		node = msh_env_get_node(env, key);
		free(key);
		free(node->value);
		node->value = msh_env_parse_value(cmd_arg);
	}
	else
	{
		if (!msh_env_add_node(&env, cmd_arg))
			return (0);
	}
	return (1);
}

static int	msh_export_add_only_key(t_env *env, char *cmd_arg)
{
	t_env	*node;
	t_env	*last_node;

	if (msh_env_key_exist(env, cmd_arg) == 1)
		return (0);
	else
	{
		if (!msh_env_new_node(&node))
			return (0);
		node->key = msh_strdup(cmd_arg);
		if (node->key == NULL)
			return (0);
		node->value = NULL;
		last_node = msh_env_last_node(env);
		last_node->next = node;
		node->prev = last_node;
	}
	return (1);
}

static int	msh_check_key(char *cmd_arg)
{
	int	i;

	i = 0;
	while (cmd_arg[i] != '=' && cmd_arg[i] != '\0')
	{
		if ((cmd_arg[i] >= 'a' && cmd_arg[i] <= 'z')
			|| (cmd_arg[i] >= 'A' && cmd_arg[i] <= 'Z')
			|| (cmd_arg[i] >= '0' && cmd_arg[i] <= '9')
			|| (cmd_arg[i] == '_'))
			i++;
		else
		{
			printf("minishell: export: `%s': not a valid identifier\n", cmd_arg);
			g_exit_status = 1;
			return (0);
		}
	}
	return (1);
}

static int	msh_is_valid_identifier(char *cmd_arg)
{
	int	i;

	i = 0;
	if ((cmd_arg[0] >= 'a' && cmd_arg[0] <= 'z')
		|| (cmd_arg[0] >= 'A' && cmd_arg[0] <= 'Z') || (cmd_arg[0] == '_'))
	{
		if (!msh_check_key(cmd_arg))
			return (0);
		return (1);
	}
	else
	{
		printf("minishell: export: `%s': not a valid identifier\n", cmd_arg);
		g_exit_status = 1;
		return (0);
	}
}

static int	msh_export_create(char *cmd_arg, t_env *env)
{
	if (!msh_is_valid_identifier(cmd_arg))
		return (0);
	if (msh_strchr(cmd_arg, '='))
	{
		if (!msh_export_add_node(env, cmd_arg))
			return (0);
	}
	else
	{
		if (!msh_export_add_only_key(env, cmd_arg))
			return (0);
	}
	return (1);
}

static int	msh_export_print(t_env *env)
{
	t_env	*node;

	node = env;
	while (node != NULL)
	{
		if (node->value == NULL)
			printf("declare -x %s\n", node->key);
		else if (!msh_strcmp(node->key, "_"))
		{
			node = node->next;
			continue ;
		}
		else
			printf("declare -x %s=\"%s\"\n", node->key, node->value);
		node = node->next;
	}
	return (1);
}

void	msh_export(char **cmd, t_env *env)
{
	int	i;
	int	argc;

	i = 1;
	argc = 0;
	while (cmd[argc] != NULL)
		argc++;
	if (argc == 1)
		msh_export_print(env);
	while (i < argc)
		msh_export_create(cmd[i++], env);
}
//= 없이 key값만 입력받은 경우에는 value가 null, export 시 =없이 출력시킴
//key가 숫자로 시작하면 에러
//이미 선언되어 있는 환경변수이면 덮어쓰기 된다. (이미 선언되어 있지만 key만 들어왔을 경우 아무런 동작x)
//여러개의 인자도 한번에 처리가 가능해야함
//인자가 export하나일 경우 선언된 환경변수를 전부 출력해주도록 함
