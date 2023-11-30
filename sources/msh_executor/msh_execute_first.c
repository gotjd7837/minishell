/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   msh_execute_first.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haekang <haekang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 14:24:03 by jho               #+#    #+#             */
/*   Updated: 2023/11/30 17:47:50 by haekang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/msh_executor.h"

int	msh_execute_first_builtin(t_pipeline *pl, int *fd, t_env *env, int forked)
{
	int		fd_cp[4];
	char	**param;

	fd_cp[0] = 0;
	fd_cp[1] = fd[1];
	if (!msh_execute_redir(pl, fd_cp))
		return (0);
	param = msh_token_filter_sym(pl->tokens, WORD);
	//if (!msh_execute_redir(pl->tokens, fd, heredoc_list))
	//	return (0);
	if (param == NULL)
		return (0);
	msh_execute_builtin(fd_cp, param, env, forked);
	if (fd_cp[0] != 0 && close(fd_cp[0]) == -1)
		return (0);
	if (fd_cp[1] != fd[1] && close(fd_cp[1]) == -1)
		return (0);
	return (1);
}

int	msh_execute_first(t_pipeline *pl, int *fd, t_env *env, int forked)
{
	int		fd_cp[4];
	pid_t	pid;
	char	**param;

	if (msh_execute_check_builtin(pl) && !forked)
		return (msh_execute_first_builtin(pl, fd, env, forked));
	fd_cp[0] = 0;
	fd_cp[1] = fd[1];
	if (!msh_execute_redir(pl, fd_cp))
		return (0);
	pid = fork();
	if (pid == -1)
		return (0);
	if (pid == 0)
	{
		set_default_signal();
		param = msh_token_filter_sym(pl->tokens, WORD);
		if (param == NULL)
			exit(errno);
		if (msh_execute_check_builtin(pl))
			msh_execute_first_builtin(pl, fd, env, forked);
		else
			msh_execute_pipeline(fd_cp[0], fd_cp[1], param, env);
	}
	if (fd_cp[0] != 0 && close(fd_cp[0]) == -1)
		return (0);
	if (fd_cp[1] != fd[1] && close(fd_cp[1]) == -1)
		return (0);
	return (1);
}
