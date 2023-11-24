/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   msh_execute.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jho <jho@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 11:55:04 by jho               #+#    #+#             */
/*   Updated: 2023/11/25 05:17:20 by jho              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/msh_executor.h"

int	msh_execute_wait_children(int children_num)
{
	while (--children_num > -1)
	{
		if (wait(&g_exit_status) == -1)
			return (0);
		g_exit_status = WEXITSTATUS(g_exit_status);
	}
	return (1);
}

int	msh_execute_free_heredoc(int fd, char *list)
{
	char *name;

	while (1)
	{
		name = get_next_line(fd);
		if (name == NULL)
			break ;
		name[msh_strlen(name) - 1] = '\0';
		unlink(name);
		free(name);
	}
	unlink(list);
	fd = 0;
	return (1);
}

int	msh_execute(t_pipeline *pipelines, t_env *env)
{
	int			children_num;
	int			fd[5];
	static char	*heredoc_list;

	children_num = 0;
	heredoc_list = msh_execute_mktemp();
	if (pipelines->next == NULL)
	{
		fd[0] = 0;
		fd[1] = 1;
		children_num += msh_execute_first(pipelines, fd, env, heredoc_list);
	}
	else
	{
		if (pipe(fd) == -1)
			return (0);
		children_num += msh_execute_first(pipelines, fd, env, heredoc_list);
		if (pipelines->next->next != NULL)
			children_num += msh_execute_middle(pipelines->next, fd, env, heredoc_list);
		children_num += msh_execute_last(msh_pipeline_last(pipelines), fd, env, heredoc_list);
	}
	msh_execute_wait_children(children_num);
	return (msh_execute_free_heredoc(fd[4], heredoc_list));
}
