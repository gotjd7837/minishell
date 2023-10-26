/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   msh_lexer.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jho <jho@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 08:43:17 by jho               #+#    #+#             */
/*   Updated: 2023/10/26 08:44:20 by jho              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MSH_LEXER_H
# define MSH_LEXER_H

typedef enum e_symbol
{
	WORD,
	ASSIGNMENT_WORD,
	REDIRECTION,
	REDIRECTION_LIST,
	PIPE,
	AND_IF,
	OR_IF,
	EQUAL_SIGN,
	L_BRACKET,
	R_BRACKET,
	SIMPLE_COMMAND_ELEMENT,
	SIMPLE_COMMAND,
	COMMAND,
	PIPELINE,
	SUBSHELL,
	LIST,
	ROOT
}	t_symbol;

#endif
