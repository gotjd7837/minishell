/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   msh_execute_last.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jho <jho@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 14:25:16 by jho               #+#    #+#             */
/*   Updated: 2023/11/25 05:08:38 by jho              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/msh_executor.h"

int	msh_execute_last_builtin(t_pipeline *pl, int *fd, t_env *env, char *heredoc_list)
{
	int		fd_cp[5];
	int		result;
	char	**param;

	fd_cp[0] = fd[0];
	close(fd[1]);
	fd_cp[1] = 1;
	if (!msh_execute_redir(pl->tokens, fd_cp, heredoc_list))
		exit(errno);
	param = msh_token_filter_sym(pl->tokens, WORD);
	if (param == NULL)
		return (0);
	result = msh_execute_builtin(fd[0], fd[1], param, env);
	close(fd[1]);
	close(fd[2]);
	close(fd_cp[0]);
	if (fd_cp[1] != 1)
		close(fd_cp[1]);
	return (result);
}

int	msh_execute_last(t_pipeline *pl, int *fd, t_env *env, char *heredoc_list)
{
	pid_t	pid;
	char	**param;
	int		fd_cp[5];

	if (msh_execute_check_builtin(pl))
		return (msh_execute_last_builtin(pl, fd, env, heredoc_list));
	fd_cp[0] = fd[0];
	close(fd[1]);
	fd_cp[1] = 1;
	if (!msh_execute_redir(pl->tokens, fd_cp, heredoc_list))
		exit(errno);
	pid = fork();
	if (pid == -1)
		return (0);
	else if (pid == 0)
	{
		param = msh_token_filter_sym(pl->tokens, WORD);
		if (param == NULL)
			exit(errno);
		msh_execute_pipeline(fd_cp[0], fd_cp[1], param, env);
	}
	close(fd[1]);
	close(fd[2]);
	close(fd_cp[0]);
	if (fd_cp[1] != 1)
		close(fd_cp[1]);
	return (1);
}
