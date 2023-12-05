/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   msh_main.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haekang <haekang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/12 12:03:25 by jho               #+#    #+#             */
/*   Updated: 2023/12/05 16:18:32 by jho              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/msh.h"
#include <string.h>
#include <errno.h>
#include "../../includes/msh_signal.h"

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
		msh_set_signal();
		input = readline("msh$> ");
		if (input == NULL)
		{
			msh_terminal_print_on();
			exit (0);
		}
		if (*input == '\0')
			continue ;
		add_history(input);
		expanded = msh_expand(input, env);
		pipelines = msh_lex(expanded);
		if (pipelines == NULL)
			printf("Lex error\n");
		else
			msh_execute(pipelines, env);
		msh_pipeline_free_list(pipelines);
		free(expanded);
		free(input);
		//system("leaks minishell | grep leaked");
	}
	return (0);
}
