/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   msh_builtin_pwd.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haekang <haekang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/14 19:54:31 by haekang           #+#    #+#             */
/*   Updated: 2023/11/25 07:11:28 by haekang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/msh_builtin.h"

int	msh_builtin_pwd(int in, int out, char **cmd, t_env *env)
{
	char	*pwd;

	(void)in;
	(void)out;
	(void)env;
	(void)cmd;
	g_exit_status = 0;
	pwd = getcwd(NULL, 0);
	if (pwd == NULL)
	{
		printf("getcwd error\n");
		g_exit_status = 1;
		return (1);
	}
	printf("%s\n", pwd);
	free(pwd);
	return (0);
}
