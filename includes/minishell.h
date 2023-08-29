/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jho <jho@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/25 15:51:41 by jho               #+#    #+#             */
/*   Updated: 2023/08/29 21:06:20 by jho              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H
# include <dirent.h>
# include <term.h>
# include <sys/ioctl.h>
# include <sys/wait.h>
# include <unistd.h>
# include <signal.h>
# include <stdio.h>
# include <stdlib.h>
# include <readline/readline.h>
# include <readline/history.h>

typedef enum e_symbol
{
	WORD,
	REDIR,
	PIPE,
	AND_IF,
	OR_IF,
	L_BR,
	R_BR,
}	t_symbol;

typedef struct s_token
{
	t_symbol		symbol;
	char			*value;
	struct s_token	*next;
}	t_token;

int			msh_append_token(t_token **tokens, t_token *token);
t_token		*msh_free_tokens(t_token *tokens);
t_token		*msh_lexical_analysis(char *input);
int			msh_strcmp(char *s1, char *s2);
int			msh_strlen(char *s);
int			msh_tokenize(t_token **tokens, char *s);
int			msh_tokenize_amp(t_token **tokens, char *str);
int			msh_tokenize_br(t_token **tokens, char *str);
int			msh_tokenize_lredir(t_token **tokens, char *str);
int			msh_tokenize_rredir(t_token **tokens, char *str);
int			msh_tokenize_vbar(t_token **tokens, char *str);
int			msh_tokenize_word(t_token **tokens, char *str);
char		*msh_substr(char *str, int startIdx, int endIdx);
#endif
