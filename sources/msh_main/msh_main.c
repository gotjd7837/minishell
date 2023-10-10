/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   msh_main.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haekang <haekang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/25 16:14:20 by jho               #+#    #+#             */
/*   Updated: 2023/10/10 17:58:47 by haekang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int	main(int ac, char **av, char **envp)
{
	// char	*input;
	t_env	*envp_list;
	// t_token	*tokens;
	t_env	*tmp;

	(void)ac;
	(void)av;
	if (msh_envp_preprocess(envp, &envp_list))
		return (1);
	tmp = envp_list;
	while (1)
	{
		if (tmp->next == NULL)
		{
			printf("key = %s value = %s\n", tmp->key, tmp->value);
			break ;
		}
		printf("key = %s value = %s\n", tmp->key, tmp->value);
		tmp = tmp->next;
	}
	printf("\nvalue = %s\n", msh_envlst_return_value(&envp_list, "TsERM"));

	// while (1)
	// {
	// 	input = readline("minishell$ ");
	// 	tokens = msh_lexical_analysis(input);
	// 	add_history(input);
	// 	msh_print_tokens(tokens);
	// 	free(input);
	// }
	return (0);
}

//gcc msh_main.c ../msh_envp_preprocess/*.c ../utils/*.c