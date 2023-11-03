/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   msh_cd.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haekang <haekang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/14 20:12:33 by haekang           #+#    #+#             */
/*   Updated: 2023/11/03 20:01:35 by haekang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/msh_builtin.h"

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
	if (oldpwd_node != NULL)
	{
		free(oldpwd_node->value);
		oldpwd_node->value = old_pwd;
	}
	else
		free(old_pwd);
	if (pwd_node != NULL)
	{
		free(pwd_node->value);
		pwd_node->value = msh_get_pwd();
		if (pwd_node->value == NULL)
			return ;
	}
}

static void	msh_cd_env(t_env *env, char *key, char *old_pwd)
{
	char	*path;

	path = msh_env_get_value(env, key);
	if (path == NULL)
	{
		path = msh_env_get_value(env, "HOME");
		if (path == NULL)
		{
			printf("minishell: cd: HOME not set\n");
			g_exit_status = 1;
			return ;
		}
	}
	if (chdir(path))
	{
		free(old_pwd);
		printf("minishell: cd: %s: No such file or directory\n", key);
		g_exit_status = 1;
		return ;
	}
	msh_fix_pwd_oldpwd(env, old_pwd);
}
//cd "" 와 같이 빈문자열이 인자로 들어오면 아무런 동작도 하지않음

void	msh_cd(char **cmd, t_env *env)
{
	char	*path;
	char	*old_pwd;

	old_pwd = msh_get_pwd();
	if (old_pwd == NULL)
		return ;
	if (msh_strcmp(cmd[1], "~") == 0 || cmd[1] == NULL)
		msh_cd_env(env, "HOME", old_pwd);
	else if (cmd[1][0] == '$' && cmd[1][1] != '\0')
		msh_cd_env(env, &(cmd[1][1]), old_pwd);
	else
	{
		path = cmd[1];
		if (chdir(path))
		{
			free(old_pwd);
			printf("minishell: cd: %s: No such file or directory\n", path);
			g_exit_status = 1;
			return ;
		}
		msh_fix_pwd_oldpwd(env, old_pwd);
	}
}
//없는 경로가 들어올 경우 에러 처리 해줘야함, 명령어 반환값 구현해야함
//환경변수에 홈 삭제됐을때 에러처리 해야함
//PWD나 OLDPWD가 없는 경우나, 둘중 하나만 있는 경우에도 잘 작동하도록