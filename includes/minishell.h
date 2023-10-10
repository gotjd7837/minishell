/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jho <jho@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/25 15:51:41 by jho               #+#    #+#             */
/*   Updated: 2023/10/10 13:56:22 by jho              ###   ########.fr       */
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

typedef struct s_comp
{
	char			*value;
	struct s_comp	*next;
}	t_comp;

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

// lexical analysis
t_token		*msh_lexical_analysis(char *input);
// lexical analysis : expand input
char		*msh_expand_input(char *input);
t_comp		*msh_divide_comps(char *input);
t_comp		*msh_last_comp(t_comp *comps);
int			msh_add_comp(t_comp **origin, char *input, int begin, int end);
int			msh_validate_dqoute(char *input, int index);
int			msh_validate_sqoute(char *input, int index);
int			(*msh_get_validator(char c))(char *input, int index);
// utils
int			msh_is_dollar(int c);
int			msh_is_dqoute(int c);
int			msh_is_sqoute(int c);
int			msh_strcmp(char *s1, char *s2);
size_t		msh_strlen(char *s);
char		*msh_strncpy(char *dest, char *src, size_t n);
#endif
