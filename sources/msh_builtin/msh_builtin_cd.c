/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   msh_builtin_cd.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haekang <haekang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/14 20:12:33 by haekang           #+#    #+#             */
/*   Updated: 2023/12/09 16:33:22 by jho              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/msh.h"

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

static char	*msh_get_pwd(int pipe)
{
	char	*pwd;

	(void)pipe;
	pwd = getcwd(NULL, 0);
	if (pwd == NULL)
		return (NULL);
	return (pwd);
}

static void	msh_fix_pwd_oldpwd(t_env *env, char *old_pwd, int pipe)
{
	t_env	*pwd_node;
	t_env	*oldpwd_node;

	if (old_pwd == NULL)
		return ;
	pwd_node = msh_env_get_node(env, "PWD");
	oldpwd_node = msh_env_get_node(env, "OLDPWD");
	if (oldpwd_node == NULL)
	{
		if (old_pwd != NULL)
			free(old_pwd);
	}
	else
	{
		free(oldpwd_node->value);
		oldpwd_node->value = old_pwd;
	}
	if (pwd_node != NULL)
	{
		free(pwd_node->value);
		pwd_node->value = msh_get_pwd(pipe);
	}
}

static int	msh_cd_env(t_env *env, char *key, char *old_pwd, int pipe)
{
	char	*path;

	path = msh_cd_env_get_value(env, key);
	if (path == NULL)
	{
		path = msh_cd_env_get_value(env, "HOME");
		if (path == NULL)
		{
			if (old_pwd != NULL)
				free(old_pwd);
			write(2, "minishell: cd: HOME not set\n", 28);
			g_exit_status = 1;
			if (pipe == 1)
				exit (g_exit_status);
			return (0);
		}
	}
	if (!msh_builtin_cd_chdir(path, old_pwd, pipe))
		return (0);
	msh_fix_pwd_oldpwd(env, old_pwd, pipe);
	return (1);
}

int	msh_builtin_cd(int *fd, int pipe, char **cmd, t_env *env)
{
	char	*path;
	char	*old_pwd;

	(void)fd;
	g_exit_status = 0;
	if (cmd[1] != NULL && cmd[1][0] == '\0')
		return (1);
	old_pwd = msh_get_pwd(pipe);
	if (cmd[1] == NULL || msh_strcmp(cmd[1], "~") == 0)
		return (msh_cd_env(env, "HOME", old_pwd, pipe));
	else if (cmd[1][0] == '$' && cmd[1][1] != '\0')
		return (msh_cd_env(env, &(cmd[1][1]), old_pwd, pipe));
	path = cmd[1];
	if (!msh_builtin_cd_chdir(path, old_pwd, pipe))
		return (0);
	msh_fix_pwd_oldpwd(env, old_pwd, pipe);
	if (pipe == 1)
		exit (g_exit_status);
	return (1);
}
