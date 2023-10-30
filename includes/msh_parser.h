/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   msh_parser.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jho <jho@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 16:41:47 by jho               #+#    #+#             */
/*   Updated: 2023/10/30 17:50:17 by jho              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MSH_PARSER_H
# define MSH_PARSER_H
# include "msh_token.h"

int			msh_accept(t_token *sym_table, t_sym sym);
t_token		*msh_parse(t_token *sym_table);
#endif
