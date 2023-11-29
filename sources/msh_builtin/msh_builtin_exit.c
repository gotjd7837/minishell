/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   msh_builtin_exit.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haekang <haekang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 20:41:04 by haekang           #+#    #+#             */
/*   Updated: 2023/11/29 16:36:02 by haekang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/msh_builtin.h"

static int	msh_exit_and_print(int exit_status, char *s)
{
	printf("exit\n");
	if (s != NULL)
		printf("minishell: exit: %s: numeric argument required\n", s);
	exit(exit_status);
}

static int	msh_check_overflow(char *str)
{
	const char	*llong_min = "-9223372036854775808";
	const char	*llong_max = "9223372036854775807";
	int			str_len;

	str_len = msh_strlen(str);
	if (str[0] == '-')
	{
		if (str_len >= 20)
		{
			if (str_len > 20 || msh_strcmp(str, (char *)llong_min) > 0)
				return (0);
		}
	}
	else
	{
		if (str_len >= 19)
		{
			if (str_len > 19 || msh_strcmp(str, (char *)llong_max) > 0)
				return (0);
		}
	}
	return (1);
}

static int	msh_num_format_exception(char *str)
{
	while (*str == ' ' || (*str >= 9 && *str <= 13))
		str++;
	if (*str == '-' || *str == '+')
		str++;
	while (*str != '\0')
	{
		if (*str >= '0' && *str <= '9')
			str++;
		else
			return (0);
	}
	return (1);
}

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

int	msh_builtin_exit(int *fd, int pipe, char **cmd, t_env *env)
{
	(void)fd;
	(void)env;
	(void)pipe;
	if (cmd[1] == NULL)
		msh_exit_and_print(g_exit_status, NULL);
	else if (cmd[1] != NULL)
	{
		if (!msh_num_format_exception(cmd[1]))
			msh_exit_and_print(255, cmd[1]);
		if (cmd[2] != NULL)
		{
			printf("exit\nminishell: exit: too many arguments\n");
			g_exit_status = 1;
			return (1);
		}
		if (!msh_check_overflow(cmd[1]))
			msh_exit_and_print(255, cmd[1]);
		else
			msh_exit_and_print((unsigned char)msh_atol(cmd[1]), NULL);
	}
	return (0);
}

//문자일때 255반환하고 exit함 -> 얘가 인자 세개보다 더 우선순위 높음
//숫자일때 long long이상이 되면 에러 출력 및, unsigned char로 타입 캐스팅한 값이 반환값, exit함
//인자 세개면 1반환하고 exit 안함