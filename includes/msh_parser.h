/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   msh_parser.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jho <jho@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 16:41:47 by jho               #+#    #+#             */
/*   Updated: 2023/10/30 22:01:05 by jho              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MSH_PARSER_H
# define MSH_PARSER_H
# include "msh_token.h"

int			msh_accept(t_token *sym_table, t_sym sym);
t_token		*msh_parse(t_token **sym_table);
int			msh_parse_cmd(t_token **parse_tree, t_token **sym_table);
int			msh_parse_list(t_token **parse_tree, t_token **sym_table);
int			msh_parse_pipeline(t_token **parse_tree, t_token **sym_table);
int			msh_parse_redir_list(t_token **parse_tree, t_token **sym_table);
int			msh_parse_simple_cmd(t_token **parse_tree, t_token **sym_table);
int			msh_parse_subshell(t_token **parse_tree, t_token **sym_table);
#endif
