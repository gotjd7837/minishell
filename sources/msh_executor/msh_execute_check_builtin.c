/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   msh_execute_check_builtin.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jho <jho@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 13:21:55 by jho               #+#    #+#             */
/*   Updated: 2023/11/24 13:42:11 by jho              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/msh_executor.h"

int	msh_execute_check_builtin(t_pipeline *pipeline)
{
	t_token	*tokens;

	tokens = pipeline->tokens;
	while (tokens != NULL)
	{
		if (tokens->sym != WORD)
			tokens = tokens->next;
		else
		{
			return (msh_strcmp(tokens->val, "echo") == 0
				|| msh_strcmp(tokens->val, "cd") == 0
				|| msh_strcmp(tokens->val, "pwd") == 0
				|| msh_strcmp(tokens->val, "export") == 0
				|| msh_strcmp(tokens->val, "unset") == 0
				|| msh_strcmp(tokens->val, "env") == 0
				|| msh_strcmp(tokens->val, "exit") == 0);
		}
	}
	return (0);
}
