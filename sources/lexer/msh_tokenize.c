/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   msh_tokenize.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jho <jho@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/29 20:49:06 by jho               #+#    #+#             */
/*   Updated: 2023/08/29 21:12:01 by jho              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int	msh_tokenize(t_token **tokens, char *s)
{
	if (*s == '<')
		return (msh_tokenize_lredir(tokens, s));
	else if (*s == '>')
		return (msh_tokenize_rredir(tokens, s));
	else if (*s == '|')
		return (msh_tokenize_vbar(tokens, s));
	else if (*s == '&')
		return (msh_tokenize_amp(tokens, s));
	else if (*s == '(' || *s == ')')
		return (msh_tokenize_br(tokens, s));
	else if (*s == ' ')
		return (1);
	else
		return (msh_tokenize_word(tokens, s));
}
