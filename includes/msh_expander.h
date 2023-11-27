/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   msh_expander.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haekang <haekang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 09:57:30 by jho               #+#    #+#             */
/*   Updated: 2023/11/27 17:30:09 by haekang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MSH_EXPANDER_H
# define MSH_EXPANDER_H
# include "msh_token.h"
# include "msh_env.h"
# include "msh_util.h"
# include "msh.h"

char		*msh_expand(char *s, t_env *env);
int			msh_replace_env(t_token **tokens, t_env *env);
t_token		*msh_replace_tokenize(char *s);
int			msh_replace_val(t_token *tokens, t_env *env);
t_token		*msh_vqoutes(char *s);
void		msh_vqoutes_idx(char *s, int **v_idx);
int			msh_vqoutes_num(char *s);
t_token		*msh_vqoutes_tokenize(char *s, int *idx, int num);
#endif
