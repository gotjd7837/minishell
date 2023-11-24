/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   msh_builtin_pwd.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haekang <haekang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/14 19:54:31 by haekang           #+#    #+#             */
/*   Updated: 2023/11/25 01:13:35 by haekang          ###   ########.fr       */
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
	pwd = getcwd(NULL, 0);
	if (pwd == NULL)
	{
		printf("getcwd error\n");
		return (1);
	}
	printf("%s\n", pwd);
	free(pwd);
	return (0);
}
