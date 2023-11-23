/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   msh_execute_middle.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jho <jho@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 14:24:44 by jho               #+#    #+#             */
/*   Updated: 2023/11/23 15:10:34 by jho              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/msh_executor.h"

void	msh_execute_middle_child(t_pipeline *pl, int *fd, t_env *env)
{
	char	**param;

	if (close(fd[1]) == -1 || close(fd[2]) == -1)
		exit(errno);
	param = msh_token_filter_sym(pl->tokens, WORD);
	if (!msh_execute_redir(pl->tokens, fd))
		exit(errno);
	if (param == NULL)
		exit(errno);
	msh_execute_pipeline(fd[0], fd[3], param, env);
}

int	msh_execute_middle(t_pipeline *pl, int *fd, t_env *env)
{
	pid_t	pid;
	int		children_num;

	children_num = 0;
	while (pl->next != NULL)
	{
		if (pipe(fd + 2) == -1)
			return (children_num);
		pid = fork();
		if (pid == -1)
			return (children_num);
		if (pid == 0)
			msh_execute_middle_child(pl, fd, env);
		++children_num;
		if (!msh_execute_pipe_shift(fd))
			return (children_num);
		pl = pl->next;
	}
	return (children_num);
}
