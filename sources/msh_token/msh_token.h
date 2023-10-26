/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   msh_token.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jho <jho@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 08:40:21 by jho               #+#    #+#             */
/*   Updated: 2023/10/26 09:18:11 by jho              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MSH_TOKEN_H
# define MSH_TOKEN_H
# include <stdlib.h>
# include "../msh_lexer/msh_lexer.h"

typedef struct s_token
{
	t_symbol		sym;
	char			*val;
	struct s_token	*next;
	struct s_token	*child;
}	t_token;

void		msh_token_add_child(t_token *parent, t_token *child);
void		msh_token_add_next(t_token *head, t_token *token);
void		msh_token_free(t_token *token);
void		msh_token_free_list(t_token *token);
void		msh_token_free_tree(t_token *root);
t_token		*msh_token_last(t_token *token);
t_token		*msh_token_malloc(void);
t_token		*msh_token_malloc_sym(t_symbol sym);
t_token		*msh_token_malloc_symval(t_symbol sym, char *val);
#endif
