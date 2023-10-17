/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   msh_main.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jho <jho@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/12 12:03:25 by jho               #+#    #+#             */
/*   Updated: 2023/10/17 14:38:22 by jho              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	leak_check(void)
{
	system("leaks minishell");
}

int	main(int argc, char *argv[], char *envp[])
{
	t_env	*env;
	char	*input;
	t_token	*tokens;

	atexit(leak_check);
	(void) argc;
	(void) argv;
	env = msh_env_new_list(envp);
	if (env == NULL)
	{
		write(2, "msh : failed to read environment.\n", 34);
		return (1);
	}
		input = readline("msh$> ");
		tokens = msh_lexical_analysis(input, env);
		free(input);
	msh_env_free_list(env);
	return (0);
}
