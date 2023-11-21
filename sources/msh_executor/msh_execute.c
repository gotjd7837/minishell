/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   msh_execute.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jho <jho@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 11:55:04 by jho               #+#    #+#             */
/*   Updated: 2023/11/21 14:58:29 by jho              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/msh_executor.h"
#include <stdio.h>
#include <errno.h>

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
			*(params + index) = msh_strdup(tokens->val);
			++index;
		}
		tokens = tokens->next;
	}
	*(params + index) = NULL;
	return (params);
}

void	pipex_filter(int in, int out, char **param, t_env *env)
{
	if (in != 0)
		dup2(in, 0);
	if (out != 1)
		dup2(out, 1);
	if (in != 0)
		close(in);
	if (out != 1)
		close(out);
	execve(msh_pathfind(param[0], env), param, NULL);
}

void	pipex_shift(int *fd)
{
	if (close(fd[0]) == -1
		|| close(fd[1]) == -1
		|| dup2(fd[2], fd[0]) == -1
		|| dup2(fd[3], fd[1]) == -1
		|| close(fd[2]) == -1
		|| close(fd[3]) == -1)
		exit(0);
}

void	pipex_filter_f2p(t_pipeline *pipeline, int *fd, t_env *env)
{
	pid_t	pid;

	pid = fork();
	if (pid == -1)
		exit(0);
	if (pid == 0)
	{
		if (fd[0] != 0)
			close(fd[0]);
		pipex_filter(0, fd[1], msh_execute_get_syms(pipeline->tokens, WORD), env);
	}
}

void	pipex_filter_p2p(t_pipeline *pipeline, int *fd, t_env *env)
{
	pid_t	pid;
	while (pipeline->next != NULL)
	{
		if (pipe(fd + 2) == -1)
			exit(errno);
		pid = fork();
		if (pid == -1)
			exit(errno);
		if (pid == 0)
		{
			close(fd[1]);
			close(fd[2]);
			pipex_filter(fd[0], fd[3], msh_execute_get_syms(pipeline->tokens, WORD), env);
		}
		pipex_shift(fd);
		pipeline = pipeline->next;
	}
}

void	pipex_filter_p2f(t_pipeline *pipeline, int *fd, t_env *env)
{
	pid_t	pid;

	pid = fork();
	if (pid == -1)
		exit(errno);
	else if (pid == 0)
	{
		if (fd[1] != 1)
			close(fd[1]);
		pipex_filter(fd[0], 1, msh_execute_get_syms(pipeline->tokens, WORD), env);
	}
	close(fd[1]);
	close(fd[0]);
}

void	msh_execute_cmd(char **params, int rfd, int wfd, t_env *env)
{
	char	*path;
	char	**envp = NULL;

	path = msh_pathfind(*params, env);
	if (rfd != 0)
		dup2(rfd, 0);
	if (wfd != 1)
		dup2(wfd, 1);
	execve(path, params, envp);
}

int	msh_execute_pipeline(t_pipeline *pipeline, int rfd, int wfd, t_env *env)
{
	char	**params;

	params = msh_execute_get_syms(pipeline->tokens, WORD);
	msh_execute_cmd(params, rfd, wfd, env);
	return (0);
}

int	msh_execute(t_pipeline *pipelines, t_env *env)
{
	int fd[4];

	if (pipelines->next == NULL)
	{
		fd[1] = 1;
		pipex_filter_f2p(pipelines, fd, env);
	}
	else
	{
		pipe(fd);
		pipex_filter_f2p(pipelines, fd, env);
		pipelines = pipelines->next;
		if (pipelines->next == NULL)
			pipex_filter_p2f(pipelines, fd, env);
		else
		{
			pipex_filter_p2p(pipelines, fd, env);
			while (pipelines->next != NULL)
				pipelines = pipelines->next;
			pipex_filter_p2f(pipelines, fd, env);
		}
	}
	wait(0);
	wait(0);
	wait(0);
	/*
	if (pid == 0)
	{
		close(fd[0]);
		msh_execute_pipeline(pipelines, 0, fd[1], env);
	}
	pid = fork();
	if (pid == 0)
	{
		close(fd[1]);
		msh_execute_pipeline(pipelines->next, fd[0], 1, env);
	}*/
	/*
	pipelines = NULL;
	env = NULL;
	if (pid == 0)
	{
		char *s[] = {"ls", "-l", NULL};
		close(fd[0]);
		dup2(fd[1], 1);
		execve("/bin/ls", s, NULL);
		printf("Failed\n");
	}
	pid = fork();
	if (pid == 0)
	{
		char *s[] = {"cat", "-e", NULL};
		close(fd[1]);
		dup2(fd[0], 0);
		execve("/bin/cat", s, NULL);
		printf("Failed\n");
	}
	*/
	return (1);
}


