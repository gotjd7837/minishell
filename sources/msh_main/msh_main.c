/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   msh_main.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haekang <haekang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/12 12:03:25 by jho               #+#    #+#             */
/*   Updated: 2023/12/09 16:58:25 by jho              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/msh.h"

t_pipeline	*msh_return_pipeline(char *input, t_env *env)
{
	t_pipeline	*pipelines;
	char		*expanded;

	expanded = msh_expand(input, env);
	if (expanded != NULL && *expanded == '\0')
	{
		if (input != NULL)
			free(input);
		return (NULL);
	}
	pipelines = msh_lex(expanded);
	if (pipelines == NULL)
	{
		write(2, "lex err\n", 8);
		g_exit_status = 258;
	}
	free(expanded);
	free(input);
	return (pipelines);
}

int	msh_check_input(char *s)
{
	if (*s == '\0')
	{
		free(s);
		return (0);
	}
	return (1);
}

int	main(int argc, char *argv[], char *envp[])
{
	char		*input;
	t_env		*env;
	t_pipeline	*pipelines;

	(void) argc;
	(void) argv;
	env = msh_env_new_list(envp);
	while (1)
	{
		msh_set_signal();
		input = readline("msh$> ");
		if (input == NULL)
			msh_handler_ctrl_d(0);
		if (!msh_check_input(input))
			continue ;
		add_history(input);
		pipelines = msh_return_pipeline(input, env);
		if (pipelines == NULL)
			continue ;
		else
			msh_execute(pipelines, env);
		msh_pipeline_free_list(pipelines);
	}
	return (0);
}
