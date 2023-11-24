/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   msh_execute_first.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jho <jho@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 14:24:03 by jho               #+#    #+#             */
/*   Updated: 2023/11/25 01:58:11 by jho              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/msh_executor.h"

int	msh_execute_first_builtin(t_pipeline *pl, int *fd, t_env *env)
{
	char **param;

	if (fd[0] != 0 && close(fd[0]) == -1)
		return (0);
	fd[0] = 0;
	param = msh_token_filter_sym(pl->tokens, WORD);
	if (!msh_execute_redir(pl->tokens, fd))
		return (0);
	if (param == NULL)
		return (0);
	return (msh_execute_builtin(fd[0], fd[1], param, env));
}

int	msh_execute_first(t_pipeline *pl, int *fd, t_env *env)
{
	pid_t	pid;
	char	**param;

	if (msh_execute_check_builtin(pl))
		return (msh_execute_first_builtin(pl, fd, env));
	pid = fork();
	if (pid == -1)
		return (0);
	if (pid == 0)
	{
		if (fd[0] != 0 && close(fd[0]) == -1)
			exit(errno);
		fd[0] = 0;
		param = msh_token_filter_sym(pl->tokens, WORD);
		if (!msh_execute_redir(pl->tokens, fd))
			exit(errno);
		if (param == NULL)
			exit(errno);
		msh_execute_pipeline(fd[0], fd[1], param, env);
	}
	return (1);
}
