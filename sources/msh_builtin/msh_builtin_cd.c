/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   msh_builtin_cd.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haekang <haekang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/14 20:12:33 by haekang           #+#    #+#             */
/*   Updated: 2023/11/25 09:09:22 by haekang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/msh_builtin.h"

static char	*msh_cd_env_get_value(t_env *env, char *key)
{
	char	*value;

	value = NULL;
	while (env != NULL)
	{
		if (!msh_strcmp(key, env->key))
		{
			value = env->value;
			return (value);
		}
		env = env->next;
	}
	return (NULL);
}

static char	*msh_get_pwd(void)
{
	char	*pwd;

	pwd = getcwd(NULL, 0);
	if (pwd == NULL)
	{
		printf("getcwd error\n");
		g_exit_status = 1;
		return (NULL);
	}
	return (pwd);
}

static void	msh_fix_pwd_oldpwd(t_env *env, char *old_pwd)
{
	t_env	*pwd_node;
	t_env	*oldpwd_node;

	pwd_node = msh_env_get_node(env, "PWD");
	oldpwd_node = msh_env_get_node(env, "OLDPWD");
	if (oldpwd_node == NULL)
		free(old_pwd);
	else
	{
		free(oldpwd_node->value);
		oldpwd_node->value = old_pwd;
	}
	if (pwd_node != NULL)
	{
		free(pwd_node->value);
		pwd_node->value = msh_get_pwd();
		if (pwd_node->value == NULL)
			return ;
	}
}

static int	msh_cd_env(t_env *env, char *key, char *old_pwd)
{
	char	*path;

	path = msh_cd_env_get_value(env, key);
	if (path == NULL)
	{
		path = msh_cd_env_get_value(env, "HOME");
		if (path == NULL)
		{
			free(old_pwd);
			printf("minishell: cd: HOME not set\n");
			g_exit_status = 1;
			return (1);
		}
	}
	if (chdir(path))
	{
		free(old_pwd);
		printf("minishell: cd: %s: No such file or directory\n", path);
		g_exit_status = 1;
		return (1);
	}
	msh_fix_pwd_oldpwd(env, old_pwd);
	return (0);
}

int	msh_builtin_cd(int in, int out, char **cmd, t_env *env)
{
	char	*path;
	char	*old_pwd;

	(void)in;
	(void)out;
	g_exit_status = 0;
	old_pwd = msh_get_pwd();
	if (old_pwd == NULL)
		return (1);
	if (cmd[1] == NULL || msh_strcmp(cmd[1], "~") == 0)
		return (msh_cd_env(env, "HOME", old_pwd));
	else if (cmd[1][0] == '$' && cmd[1][1] != '\0')
		return (msh_cd_env(env, &(cmd[1][1]), old_pwd));
	path = cmd[1];
	if (chdir(path))
	{
		free(old_pwd);
		printf("minishell: cd: %s: No such file or directory\n", path);
		g_exit_status = 1;
		return (1);
	}
	msh_fix_pwd_oldpwd(env, old_pwd);
	return (0);
}
