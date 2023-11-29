/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   msh_builtin_echo.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haekang <haekang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/16 18:19:33 by haekang           #+#    #+#             */
/*   Updated: 2023/11/29 17:46:39 by haekang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/msh_builtin.h"

static void	msh_get_start_idx(char **cmd, int *start_idx, int i)
{
	int	j;

	while (cmd[i] != NULL)
	{
		if (cmd[i][0] == '-' && cmd[i][1] == 'n')
		{
			j = 2;
			while (cmd[i][j] == 'n')
				j++;
			if (cmd[i][j] != '\0')
			{
				*start_idx = i;
				break ;
			}
		}
		else
		{
			*start_idx = i;
			break ;
		}
		i++;
	}
	if (cmd[i] == NULL)
		*start_idx = i;
}

static void	msh_check_option(char **cmd, int *n_flag)
{
	int	i;
	int	j;

	i = 1;
	if (cmd[i] == NULL || !(cmd[i][0] == '-' && cmd[i][1] == 'n'))
		return ;
	while (cmd[i] != NULL)
	{
		if (cmd[i][0] == '-' && cmd[i][1] == 'n')
		{
			j = 2;
			while (cmd[i][j] == 'n')
				j++;
			if (cmd[i][j] == '\0')
				*n_flag = 1;
		}
		i++;
	}
	return ;
}

int	msh_builtin_echo(int *fd, int pipe, char **cmd, t_env *env)
{
	int		n_flag;
	int		start_idx;
	int		i;

	(void)env;
	i = 1;
	n_flag = 0;
	start_idx = 1;
	msh_check_option(cmd, &n_flag);
	msh_get_start_idx(cmd, &start_idx, 1);
	while (cmd[start_idx] != NULL)
	{
		write(fd[1], cmd[start_idx], msh_strlen(cmd[start_idx]));
		if (cmd[++start_idx] != NULL)
			write(fd[1], " ", 2);
	}
	if (n_flag == 0)
		write(fd[1], "\n", 2);
	g_exit_status = 0;
	if (pipe == 1)
		exit(g_exit_status);
	return (0);
}
