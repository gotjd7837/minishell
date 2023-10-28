/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   msh_lexer.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jho <jho@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/27 21:31:00 by jho               #+#    #+#             */
/*   Updated: 2023/10/28 08:52:32 by jho              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MSH_LEXER_H
# define MSH_LEXER_H
# include "msh_token.h"
# include "msh_util.h"

t_token		*msh_lex(char *s);
int			msh_lex_tokenize(t_token **sym_table, char *s);
int			msh_lex_tokenize_and_if(t_token **sym_table, char *s);
int			msh_lex_tokenize_bra(t_token **sym_table, char *s);
int			msh_lex_tokenize_or_if(t_token **sym_table, char *s);
int			msh_lex_tokenize_pipe(t_token **sym_table, char *s);
int			msh_lex_tokenize_qoutes(t_token **sym_table, char *s);
int			msh_lex_tokenize_redir(t_token **sym_table, char *s);
int			msh_lex_tokenize_word(t_token **sym_table, char *s);
#endif
