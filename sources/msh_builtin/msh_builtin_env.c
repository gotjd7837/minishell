/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   msh_builtin_env.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haekang <haekang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 20:07:51 by haekang           #+#    #+#             */
/*   Updated: 2023/11/25 05:25:33 by haekang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/msh_builtin.h"

int	msh_builtin_env(int in, int out, char **cmd, t_env *env)
{
	t_env	*node;

	(void)in;
	(void)cmd;
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