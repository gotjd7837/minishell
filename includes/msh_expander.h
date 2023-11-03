/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   msh_expander.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jho <jho@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 09:57:30 by jho               #+#    #+#             */
/*   Updated: 2023/10/27 21:08:17 by jho              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MSH_EXPANDER_H
# define MSH_EXPANDER_H
# include "msh_token.h"
# include "msh_env.h"
# include "msh_util.h"

char		*msh_expand(char *s, t_env *env);
int			msh_replace_env(t_token **tokens, t_env *env);
t_token		*msh_replace_tokenize(char *s);
int			msh_replace_val(t_token *tokens, t_env *env);
t_token		*msh_vqoutes(char *s);
void		msh_vqoutes_idx(char *s, int **v_idx);
int			msh_vqoutes_num(char *s);
t_token		*msh_vqoutes_tokenize(char *s, int *idx, int num);
#endif
