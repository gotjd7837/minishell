/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jho <jho@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/25 15:51:41 by jho               #+#    #+#             */
/*   Updated: 2023/10/09 12:42:54 by jho              ###   ########.fr       */
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
	ASSIGNMENT_WORD,
	REDIRECTION,
	PIPE,
	AND_IF,
	OR_IF,
	L_BRACKET,
	R_BRACKET,
	EQUAL_SIGN,
	SIMPLE_COMMAND_ELEMENT,
	SIMPLE_COMMAND,
	COMMAND,
	PILELINE,
	SUBSHELL,
	LIST,
	ROOT
}	t_symbol;

typedef struct s_token
{
	t_symbol		symbol;
	char			*value;
	struct s_token	*next;
}	t_token;

typedef struct s_tree
{
	t_symbol		symbol;
	char			*value;
	struct s_tree	*children;
}	t_tree;

int			msh_validate_quotes(char *input);
int			msh_accept(t_symbol symbol, t_token *tokens);
int			msh_append_token(t_token **tokens, t_token *token);
int			msh_count_equal_sign(char *s);
t_token		*msh_free_tokens(t_token *tokens);
int			msh_is_meta_char(char c);
int			msh_is_meta_char_2(char c);
t_token		*msh_lexical_analysis(char *input);
t_tree		*msh_parse(t_token *tokens);
int			msh_strcmp(char *s1, char *s2);
int			msh_strlen(char *s);
int			msh_tokenize(t_token **tokens, char *s);
int			msh_tokenize_amp(t_token **tokens, char *str);
int			msh_tokenize_equal_sign(t_token **tokens, char *str);
int			msh_tokenize_br(t_token **tokens, char *str);
int			msh_tokenize_redir(t_token **tokens, char *str);
int			msh_tokenize_vbar(t_token **tokens, char *str);
int			msh_tokenize_word(t_token **tokens, char *str);
char		*msh_substr(char *str, int startIdx, int endIdx);
int			msh_whitespace_len(char *s);
#endif
