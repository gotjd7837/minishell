/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   msh_expander.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jho <jho@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 09:57:30 by jho               #+#    #+#             */
/*   Updated: 2023/10/26 15:42:05 by jho              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MSH_EXPANDER_H
# define MSH_EXPANDER_H
# include "msh_token.h"
# include "msh_util.h"

char		*msh_expand(char *s);
t_token		*msh_vqoutes(char *s);
t_token		*msh_vqoutes_add_token(t_token **tokens, char *s, int begin, int end);
void		msh_vqoutes_idx(char *s, int **v_idx);
int			msh_vqoutes_num(char *s);
t_token		*msh_vqoutes_tokenize(char *s, int *idx, int num);
#endif
