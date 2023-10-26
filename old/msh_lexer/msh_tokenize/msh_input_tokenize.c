/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   msh_input_tokenize.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haekang <haekang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/29 20:49:06 by jho               #+#    #+#             */
/*   Updated: 2023/10/20 15:21:03 by haekang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/minishell.h"

int	msh_input_tokenize(t_token **tokens, char *s)
{
	if (*s == '<' | *s == '>')
		return (msh_tokenize_redir(tokens, s));
	else if (*s == '|')
		return (msh_tokenize_vbar(tokens, s));
	else if (*s == '&')
		return (msh_tokenize_amp(tokens, s));
	else if (*s == '(' || *s == ')')
		return (msh_tokenize_br(tokens, s));
	else if (*s == ' ')
		return (1);
	else if (*s == '=')
		return (msh_tokenize_equal_sign(tokens, s));
	else
		return (msh_tokenize_word(tokens, s));
}
