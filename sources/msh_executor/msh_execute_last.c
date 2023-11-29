/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   msh_execute_last.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haekang <haekang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 14:25:16 by jho               #+#    #+#             */
/*   Updated: 2023/11/29 17:03:12 by jho              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/msh_executor.h"

int	msh_execute_last_builtin(t_pipeline *pl, int *fd, t_env *env)
{
	int		fd_cp[4];
	int		result;
	char	**param;

	fd_cp[0] = fd[0];
	if (close(fd[1]))
		return (0);
	fd_cp[1] = 1;
	if (!msh_execute_redir(pl, fd_cp))
		exit(errno);
	param = msh_token_filter_sym(pl->tokens, WORD);
	if (param == NULL)
		exit(errno);
	result = msh_execute_builtin(fd_cp, param, env, 1);
	if (close(fd[1]) == -1 || close(fd[2]) == -1 || close(fd_cp[0]) == -1)
		exit(errno);
	if (fd_cp[1] != 1 && close(fd_cp[1]) == -1)
		exit(errno);
	return (result);
}

int	msh_execute_last(t_pipeline *pl, int *fd, t_env *env)
{
	pid_t	pid;
	char	**param;
	int		fd_cp[4];

	if (fd[1] != 1 && close(fd[1]) == -1)
		return (0);
	fd_cp[0] = fd[0];
	fd_cp[1] = 1;
	if (!msh_execute_redir(pl, fd_cp))
		return (0);
	pid = fork();
	if (pid == -1)
		return (0);
	else if (pid == 0)
	{
		param = msh_token_filter_sym(pl->tokens, WORD);
		if (param == NULL)
			exit(errno);
		if (msh_execute_check_builtin(pl))
			msh_execute_last_builtin(pl, fd, env);
		else
			msh_execute_pipeline(fd_cp[0], fd_cp[1], param, env);
	}
	close(fd[2]);
	close(fd_cp[0]);
	if (fd_cp[1] != 1 && close(fd_cp[1]) == -1)
		exit(errno);
	return (1);
}
