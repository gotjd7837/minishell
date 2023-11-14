/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   msh_token.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jho <jho@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 08:40:21 by jho               #+#    #+#             */
/*   Updated: 2023/11/14 14:43:55 by jho              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MSH_TOKEN_H
# define MSH_TOKEN_H
# include <stdlib.h>
# include "msh_util.h"

typedef enum e_sym
{
	WORD,
	ASSIGN_WORD,
	REDIR,
	PIPE,
	AND_IF,
	OR_IF,
	L_BRA,
	R_BRA,
	REDIR_LIST,
	SIMPLE_CMD,
	CMD,
	PIPELINE,
	LIST,
	SUBSHELL,
	ROOT,
	UNDEFINED
}	t_sym;

typedef struct s_token
{
	t_sym			sym;
	char			*val;
	struct s_token	*next;
	struct s_token	*child;
}	t_token;

void	msh_token_add_child(t_token **parent, t_token *child);
void	msh_token_add_next(t_token **head, t_token *token);
t_token	*msh_token_add_substr(t_token **tokens, char *s, int begin, int end);
t_token	*msh_token_dequeue(t_token **tokens);
t_token	*msh_token_free(t_token *token);
t_token	*msh_token_free_list(t_token *token);
t_token	*msh_token_free_tree(t_token *root);
t_token	*msh_token_last(t_token *token);
int		msh_token_len_val(t_token *token);
t_token	*msh_token_malloc(void);
t_token	*msh_token_malloc_sym(t_sym sym);
t_token	*msh_token_malloc_symval(t_sym sym, char *val);
t_token	*msh_token_malloc_val(char *val);
void	msh_token_print_list(t_token *list);
void	msh_token_print_tree(t_token *tree, int depth);
void	msh_token_remove_front(t_token **tokens);
char	*msh_token_union_val(t_token *token);
#endif
