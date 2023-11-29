/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   msh_main.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haekang <haekang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/12 12:03:25 by jho               #+#    #+#             */
/*   Updated: 2023/11/29 18:59:41 by jho              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/msh.h"

int	main(int argc, char *argv[], char *envp[])
{
	char		*input;
	t_env		*env;
	char		*expanded;
	t_pipeline	*pipelines;

	(void) argc;
	(void) argv;
	env = msh_env_new_list(envp);
	while (1)
	{
		input = readline("msh$> ");
		expanded = msh_expand(input, env);
		pipelines = msh_lex(expanded);
		if (pipelines == NULL)
		{
			printf("Lex error\n");
			free(input);
			free(expanded);
			continue ;
		}
		msh_execute(pipelines, env);
		msh_pipeline_free_list(pipelines);
		free(expanded);
		free(input);
		system("leaks minishell | grep leaked");
	}
	return (0);
}
