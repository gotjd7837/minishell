/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   msh_builtin_export.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haekang <haekang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/27 21:49:34 by haekang           #+#    #+#             */
/*   Updated: 2023/11/25 05:17:47 by haekang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/msh_builtin.h"

int	msh_builtin_export(int in, int out, char **cmd, t_env *env)
{
	int	i;
	int	argc;

	(void)in;
	i = 1;
	argc = 0;
	g_exit_status = 0;
	while (cmd[argc] != NULL)
		argc++;
	if (argc == 1)
		msh_export_print(env, out);
	while (i < argc)
	{
		if (!msh_export_create(cmd[i++], env))
			g_exit_status = 1;
	}
	return (0);
}
//= 없이 key값만 입력받은 경우에는 value가 null, export 시 =없이 출력시킴
//key가 숫자로 시작하면 에러
//이미 선언되어 있는 환경변수이면 덮어쓰기 된다. (이미 선언되어 있지만 key만 들어왔을 경우 아무런 동작x)
//여러개의 인자도 한번에 처리가 가능해야함
//인자가 export하나일 경우 선언된 환경변수를 전부 출력해주도록 함



//에러코드는 표표준준출출력력으으로  내뱉음