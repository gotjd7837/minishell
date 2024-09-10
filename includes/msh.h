/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   msh.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haekang <haekang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 12:29:19 by jho               #+#    #+#             */
/*   Updated: 2023/12/06 16:35:58 by haekang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MSH_H
# define MSH_H
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
# include <errno.h>
# include <sys/stat.h>
# include <string.h>
# include <fcntl.h>
# include "get_next_line.h"
# define UNFORKED 0
# define FORKED 1

extern int		g_exit_status;

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

typedef struct s_env
{
	char			*key;
	char			*value;
	struct s_env	*next;
	struct s_env	*prev;
}	t_env;

typedef struct s_token
{
	t_sym			sym;
	char			*val;
	struct s_token	*next;
	struct s_token	*child;
}	t_token;

typedef struct s_heredoc
{
	int					fd;
	char				*name;
	struct s_heredoc	*next;
}	t_heredoc;

typedef struct s_pipeline
{
	t_token				*tokens;
	struct s_pipeline	*next;
	t_heredoc			*heredoc;
	pid_t				pid;
}	t_pipeline;

//msh_env
int			msh_env_add_node(t_env **list, char *envp);
t_env		*msh_env_free_list(t_env *list);
t_env		*msh_env_free_node(t_env *node);
t_env		*msh_env_get_node(t_env *env, char *key);
char		*msh_env_get_value(t_env *env, char *key);
t_env		*msh_env_last_node(t_env *list);
t_env		*msh_env_new_list(char *envp[]);
int			msh_env_new_node(t_env **node);
char		*msh_env_parse_key(char *envp);
char		*msh_env_parse_value(char *envp);
char		**msh_env_convert_arr(t_env *env);

//msh_signal
void		msh_set_signal(void);
void		msh_set_blocking_signal(void);
void		msh_set_default_signal(void);
void		msh_handler_ctrl_c(int signum);
void		msh_handler_ctrl_d(int signum);
void		msh_handler_heredoc_ctrl_c(int signum);
void		msh_handler_blocking_ctrl_c(int signum);
void		msh_handler_blocking_ctrl_slash(int signum);
void		msh_terminal_print_on(void);
void		msh_terminal_print_off(void);

//msh_expand
char		*msh_expand(char *s, t_env *env);
int			msh_trim_both_end(t_token **tokens);
char		*msh_expand_heredoc(char *s, t_env *env);
int			msh_replace_env(t_token **tokens, t_env *env);
t_token		*msh_replace_tokenize(char *s);
int			msh_replace_val(t_token *tokens, t_env *env);
t_token		*msh_vqoutes(char *s);
void		msh_vqoutes_idx(char *s, int **v_idx);
int			msh_vqoutes_num(char *s);
t_token		*msh_vqoutes_tokenize(char *s, int *idx, int num);

//msh_token
void		msh_token_add_child(t_token **parent, t_token *child);
void		msh_token_add_next(t_token **head, t_token *token);
t_token		*msh_token_add_substr(t_token **token, char *s, int begin, int end);
int			msh_token_count_sym(t_token *tokens, t_sym sym);
t_token		*msh_token_dequeue(t_token **tokens);
char		**msh_token_filter_sym(t_token *tokens, t_sym sym);
t_token		*msh_token_free(t_token *token);
t_token		*msh_token_free_list(t_token *token);
t_token		*msh_token_free_tree(t_token *root);
t_token		*msh_token_last(t_token *token);
int			msh_token_len_val(t_token *token);
t_token		*msh_token_malloc(void);
t_token		*msh_token_malloc_sym(t_sym sym);
t_token		*msh_token_malloc_symval(t_sym sym, char *val);
t_token		*msh_token_malloc_val(char *val);
void		msh_token_print_list(t_token *list);
void		msh_token_print_tree(t_token *tree, int depth);
void		msh_token_remove_front(t_token **tokens);
char		*msh_token_union_val(t_token *token);

//msh_pipeline
t_heredoc	*msh_heredoc_malloc(int fd, char *name);
int			msh_pipeline_add_heredoc(t_pipeline *pipeline, t_heredoc *heredoc);
int			msh_pipeline_add_node(t_pipeline **head, t_pipeline *pipeline);
t_pipeline	*msh_pipeline_last(t_pipeline *pipelines);
t_pipeline	*msh_pipeline_free_list(t_pipeline *pipeline);
t_pipeline	*msh_pipeline_malloc(void);

//msh_lexer
t_pipeline	*msh_lex(char *s);
int			msh_lex_tokenize(t_token **sym_table, char *s);
int			msh_lex_tokenize_and_if(t_token **sym_table, char *s);
int			msh_lex_tokenize_bra(t_token **sym_table, char *s);
int			msh_lex_tokenize_or_if(t_token **sym_table, char *s);
int			msh_lex_tokenize_pipe(t_token **sym_table, char *s);
int			msh_lex_tokenize_qoutes(t_token **sym_table, char *s);
int			msh_lex_tokenize_redir(t_token **sym_table, char *s);
int			msh_lex_tokenize_word(t_token **sym_table, char *s);

//msh_builtin
int			msh_builtin_cd(int *fd, int pipe, char **cmd, t_env *env);
int			msh_builtin_cd_chdir(char *path, char *old_pwd, int pipe);
int			msh_builtin_echo(int *fd, int pipe, char **cmd, t_env *env);
int			msh_builtin_env(int *fd, int pipe, char **cmd, t_env *env);
int			msh_builtin_exit(int *fd, int pipe, char **cmd, t_env *env);
int			msh_builtin_pwd(int *fd, int pipe, char **cmd, t_env *env);
int			msh_builtin_unset(int *fd, int pipe, char **cmd, t_env *env);
int			msh_builtin_export(int *fd, int pipe, char **cmd, t_env *env);
int			msh_export_print(t_env *env, int out);
int			msh_export_create(char *cmd_arg, t_env *env);
int			msh_is_valid_identifier(char *cmd_arg);
int			msh_check_key(char *cmd_arg);
int			msh_export_key_exist(t_env *env, char *key);

//msh_pathfinder
char		*msh_pathfinder(char *cmd, t_env *env);
char		*msh_pathfinder_unset_path(char *cmd);
int			msh_pathfinder_is_path(char *cmd);
int			msh_pathfinder_is_dir(char *path);
char		**msh_pathfinder_find_env_path(t_env *env);
char		*msh_pathfinder_find_cmd_abspath(char **path, char *cmd);
char		*msh_pathfinder_check_path_exist(char *cmd);

//msh_executor
int			msh_execute(t_pipeline *pipelines, t_env *env);
int			msh_execute_builtin(int *fd, char **param, t_env *env, int forked);
int			msh_execute_check_builtin(t_pipeline *pipeline);
int			msh_execute_first(t_pipeline *pl, int *fd, t_env *env, int forked);
void		msh_execute_free_param(char **param);
int			msh_execute_last(t_pipeline *pl, int *fd, t_env *env);
int			msh_execute_middle(t_pipeline *pl, int *fd, t_env *env);
char		*msh_execute_mktemp(void);
int			msh_execute_pipe_shift(int *fd, int *local_fd);
void		msh_execute_pipeline(int in, int out, char **param, t_env *env);
int			msh_execute_redir(t_pipeline *pl, int *fd, t_env *env);
int			msh_execute_redir_hdoc(t_pipeline *p, char *l, int *fd, t_env *env);
void		msh_exit(int exit_code);

//msh_utill
int			msh_is_charset(char c, char *set);
int			msh_is_whitespace(char c);
char		*msh_strchr(char *s, int c);
int			msh_strcmp(char *s1, char *s2);
void		msh_strcpy(char *dest, char *src);
char		*msh_strdup(char *s1);
int			msh_strlen(char *s);
char		*msh_strncpy(char *dest, char *src, size_t n);
char		*msh_substr(char *str, int begin, int end);
char		**msh_split(char *s, char c);
char		*msh_strjoin(char *s1, char *s2);
size_t		msh_strlcpy(char *dst, char *src, size_t dstsize);
char		*msh_itoa(int n);
char		*msh_remove_whitespace(char *s);

#endif
