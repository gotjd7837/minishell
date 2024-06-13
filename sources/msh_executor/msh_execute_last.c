/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   msh_execute_last.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haeseong <haeseong@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 14:25:16 by jho               #+#    #+#             */
/*   Updated: 2024/06/13 21:45:48 by haeseong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/msh.h"

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
	int		local_fd[4];

	close(fd[1]);
	local_fd[0] = fd[0];
	local_fd[1] = 1;
	if (msh_execute_redir(pl, local_fd, env) != 1) // 리다이렉션 실행
		return (-1);
	pl->pid = fork();
	if (pl->pid == -1)
		msh_exit(errno);
	else if (pl->pid == 0)
	{
		msh_set_default_signal(); // 시그널 회복
		msh_execute_last_child(pl, local_fd, env);
	}
	msh_set_blocking_signal();
	close(fd[0]);
	close(local_fd[0]);
	if (local_fd[1] != 1)
		close(local_fd[1]);
	return (1);
}
