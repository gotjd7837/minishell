/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   msh_execute.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jho <jho@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 11:55:04 by jho               #+#    #+#             */
/*   Updated: 2023/11/14 14:45:00 by jho              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/msh_executor.h"

int	msh_execute_count_sym(t_token *tokens, t_sym sym)
{
	int	count;

	count = 0;
	while (tokens != NULL)
	{
		count += tokens->sym == sym;
		tokens = tokens->next;
	}
	return (count);
}

char	**msh_execute_get_syms(t_token *tokens, t_sym sym)
{
	char	**params;
	int		index;

	params = malloc(sizeof(char *) * msh_execute_count_sym(tokens, sym) + 1);
	if (params == NULL)
		return (NULL);
	index = 0;
	while (tokens != NULL)
	{
		if (tokens->sym == sym)
		{
			*(params + index) = msh_strdup(tokens->value);
			++index;
		}
		tokens = tokens->next;
	}
	*(params + index) = NULL;
	return (params);
}

void	msh_execute_heredoc(char *limiter)
{

}

void	msh_execute_redir(char **redirs, int *rfd, int *wfd)
{
	char	*redir;

	while (*redirs != NULL)
	{
		redir = *redirs;
		if (*redir == '<' && *(redir + 1) == '<')
			*rfd = msh_execute_heredoc(redir);
		else if (*redir == '<')
			*rfd = msh_execute_in_redir(redir);
		else if(*redir == '>' && *(redir + 1) == '>')
			*wfd = msh_execute_append(redir);
		else if (*redir == '>')
			*wfd = msh_execute_out_redir(redir);
		++redirs;
	}
}

void	msh_execute_cmd(char **params, int rfd, int wfd, t_env *env)
{
	char	*path;
	char	**envp;

	dup2(rfd, 0);
	dup2(wfd, 1);
	path = msh_pathfind(*params);
	envp = msh_env_convert_char(env);
	execve(path, params, envp);
}

int	msh_execute_pipeline(t_pipeline *pipeline, int rfd, int wfd)
{
	pid_t	pid;
	char	**params;
	char	**redirs;

	params = msh_execute_get_syms(pipeline->tokens, WORD);
	redirs = msh_execute_get_syms(pipeline->tokens, REDIR);
	pid = fork();
	if (pid == 0)
	{
		msh_execute_redir(redirs, &rfd, &wfd);
		msh_execute_cmd(params, rfd, wfd);
	}
	return (0);
}

int	msh_execute_shift_pipe(int *fd)
{
	close(fd[0]);
	close(fd[1]);
	dup2(fd[2], fd[0]);
	dup2(fd[3], fd[1]);
	close(fd[2]);
	close(fd[3]);
}

int	msh_execute(t_pipeline *pipelines)
{
	int fd[4];

	fd[0] = 0;
	fd[1] = 1;
	while (pipelines != NULL)
	{
		if (pipelines->next != NULL)
			pipe(fd + 2);
		else
			fd[3] = 1;
		msh_execute_pipeline(pipeline, fd[0], fd[3]);
		msh_execute_shift_pipe(fd);
		pipelines = pipelines->next;
	}
}


