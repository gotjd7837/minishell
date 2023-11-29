/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   msh_builtin_env.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haekang <haekang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 20:07:51 by haekang           #+#    #+#             */
/*   Updated: 2023/11/29 16:41:19 by jho              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/msh_builtin.h"

int	msh_builtin_env(int *fd, char **cmd, t_env *env, int forked)
{
	t_env	*node;
	int		out;

	out = fd[1];
	(void)cmd;
	(void)forked;
	node = env;
	while (node != NULL)
	{
		if (node->value != NULL)
		{
			write(out, node->key, msh_strlen(node->key));
			write(out, "=", 2);
			write(out, node->value, msh_strlen(node->value));
			write(out, "\n", 2);
		}
		node = node->next;
	}
	g_exit_status = 0;
	return (0);
}
//export로 '='없이 선언된 변수는 value=NULL로 만들어 구분한다.
//env는 key=value 구조만 출력한다.
//실제 zsh->bash에서도 key=value구조로 선언된 환경변수만을 가져온다.
