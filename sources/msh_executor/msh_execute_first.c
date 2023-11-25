/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   msh_execute_first.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jho <jho@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 14:24:03 by jho               #+#    #+#             */
/*   Updated: 2023/11/25 05:25:58 by jho              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/msh_executor.h"

int	msh_execute_first_builtin(t_pipeline *pl, int *fd, t_env *env, char *heredoc_list)
{
	int		fd_cp[5];
	char	**param;

	fd_cp[0] = 0;
	fd_cp[1] = fd[1];
	if (!msh_execute_redir(pl->tokens, fd_cp, heredoc_list))
		return (0);
	param = msh_token_filter_sym(pl->tokens, WORD);
	if (!msh_execute_redir(pl->tokens, fd, heredoc_list))
		return (0);
	if (param == NULL)
		return (0);
	msh_execute_builtin(fd_cp[0], fd_cp[1], param, env);
	if (fd_cp[0] != 0)
		close(fd_cp[0]);
	if (fd_cp[1] != fd[1])
		close(fd_cp[1]);
	return (1);
}

int	msh_execute_first(t_pipeline *pl, int *fd, t_env *env, char *heredoc_list)
{
	int		fd_cp[5];
	pid_t	pid;
	char	**param;

	if (msh_execute_check_builtin(pl))
		return (msh_execute_first_builtin(pl, fd, env, heredoc_list));
	fd_cp[0] = 0;
	fd_cp[1] = fd[1];
	if (!msh_execute_redir(pl->tokens, fd_cp, heredoc_list))
		return (0);
	pid = fork();
	if (pid == -1)
		return (0);
	if (pid == 0)
	{
		param = msh_token_filter_sym(pl->tokens, WORD);
		if (param == NULL)
			exit(errno);
		msh_execute_pipeline(fd_cp[0], fd_cp[1], param, env);
	}
	if (fd_cp[0] != 0)
		close(fd_cp[0]);
	if (fd_cp[1] != fd[1])
		close(fd_cp[1]);
	return (1);
}
