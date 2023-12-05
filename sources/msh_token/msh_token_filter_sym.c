/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   msh_token_filter_sym.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haekang <haekang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 14:14:34 by jho               #+#    #+#             */
/*   Updated: 2023/12/05 19:38:30 by haekang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/msh.h"

char	**msh_token_filter_sym_free(char **result, int size)
{
	int	index;

	if (result == NULL)
		return (0);
	index = -1;
	while (++index < size)
		free(*(result + index));
	free(result);
	return (NULL);
}

char	**msh_token_filter_sym(t_token *tokens, t_sym sym)
{
	char	**result;
	int		index;

	if (tokens == NULL)
		return (NULL);
	result = malloc(sizeof(char *) * msh_token_count_sym(tokens, sym) + 1);
	if (result == NULL)
		return (NULL);
	index = 0;
	while (tokens != NULL)
	{
		if (tokens->sym == sym)
		{
			*(result + index) = msh_strdup(tokens->val);
			if (*(result + index) == NULL)
				return (msh_token_filter_sym_free(result, index + 1));
			++index;
		}
		tokens = tokens->next;
	}
	*(result + index) = NULL;
	return (result);
}
