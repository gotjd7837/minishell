/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   msh_exit.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haekang <haekang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 20:41:04 by haekang           #+#    #+#             */
/*   Updated: 2023/10/24 18:38:12 by haekang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

#include "../../includes/minishell.h"

static long long	msh_atol(char *str)
{
	int			flag;
	long long	result;

	flag = 1;
	result = 0;
	while (*str == ' ' || (*str >= 9 && *str <= 13))
		str++;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			flag = -1;
		str++;
	}
	while (*str >= '0' && *str <= '9')
		result = result * 10 + (*str++ - '0');
	return (result * flag);
}

void	msh_exit(char **cmd)
{
	int	i;

	printf("exit\n");
	if (cmd[1] == NULL)
	{
		g_exit_status = 0;
		exit(0);
	}
	else if (cmd[1] != NULL && cmd[2] == NULL)
	{
		g_exit_status = (unsigned char)msh_atol(cmd[1]);
		exit(g_exit_status);
	}
	else
	{
		exit(1);
	}
}
//숫자일때 long long이상이 되면 에러 출력 및, unsigned char로 타입 캐스팅한 값이 반환값, exit함
//문자일때 255반환하고 exit함 -> 얘가 인자 세개보다 더 우선순위 높음
//인자 세개면 1반환하고 exit 안함