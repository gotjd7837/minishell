/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   msh_tokenize_redir.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jho <jho@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/12 16:13:38 by jho               #+#    #+#             */
/*   Updated: 2023/09/12 16:31:36 by jho              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int	msh_tokenize_redir(t_token **tokens, char *str)
{
	int		end_idx;
	t_token	*token;
	char	*value;

	if (*(str + 1) == '<' || *(str + 1) == '>')
		end_idx = 2;
	else
		end_idx = 1;
	end_idx += msh_whitespace_len(str + end_idx);
	if (msh_is_meta_char(*(str + end_idx)))
		return (-1);
	while (!msh_is_meta_char(*(str + end_idx)))
		++end_idx;
	value = msh_substr(str, 0, end_idx);
	if (value == 0)
		return (-1);
	token = malloc(sizeof(t_token));
	if (token == 0)
	{
		free(value);
		return (-1);
	}
	token->symbol = REDIRECTION;
	token->value = value;
	token->next = 0;
	msh_append_token(tokens, token);
	return (msh_strlen(value));
}
