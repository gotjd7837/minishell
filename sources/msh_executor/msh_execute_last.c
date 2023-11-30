/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   msh_execute_last.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haekang <haekang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 14:25:16 by jho               #+#    #+#             */
/*   Updated: 2023/11/30 16:17:20 by jho              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/msh_executor.h"

int	msh_execute_last_builtin(int *fd, t_env *env, char **param)
{
	int		result;

	result = msh_execute_builtin(fd, param, env, FORKED);
	exit(g_exit_status);
	return (result);
}

void	msh_execute_last_child(t_pipeline *pl, int *fd, t_env *env)
{
	char	**param;

	param = msh_token_filter_sym(pl->tokens, WORD);
	if (param == NULL)
		exit(errno);
	if (msh_execute_check_builtin(pl))
		msh_execute_last_builtin(fd, env, param);
	else
		msh_execute_pipeline(fd[0], fd[1], param, env);
}

int	msh_execute_last(t_pipeline *pl, int *fd, t_env *env)
{
	pid_t	pid;
	int		local_fd[4];

	close(fd[1]);
	local_fd[0] = fd[0];
	local_fd[1] = 1;
	if (msh_execute_redir(pl, local_fd) != 1)
		return (-1);
	pid = fork();
	if (pid == -1)
		return (-1);
	else if (pid == 0)
		msh_execute_last_child(pl, local_fd, env);
	close(fd[0]);
	close(local_fd[0]);
	if (local_fd[1] != 1)
		close(local_fd[1]);
	return (1);
}
