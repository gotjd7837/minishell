# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: haekang <haekang@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/08/25 15:50:06 by jho               #+#    #+#              #
#    Updated: 2023/12/09 16:20:16 by haekang          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
CFLAGS = -Wall -Wextra -Werror
LDFLAGS = -lreadline -lncurses
NAME = minishell
HEADERS = ./includes
MANDATORY_SRCS = sources/get_next_line/get_next_line.c \
	sources/get_next_line/get_next_line_utils.c \

	sources/msh_builtin/msh_builtin_cd_chdir.c \
	sources/msh_builtin/msh_builtin_cd.c \
	sources/msh_builtin/msh_builtin_echo.c \
	sources/msh_builtin/msh_builtin_env.c \
	sources/msh_builtin/msh_builtin_exit.c \
	sources/msh_builtin/msh_builtin_export_create.c\
	sources/msh_builtin/msh_builtin_export_print.c \
	sources/msh_builtin/msh_builtin_export_util.c \
	sources/msh_builtin/msh_builtin_export.c \
	sources/msh_builtin/msh_builtin_pwd.c \
	sources/msh_builtin/msh_builtin_unset.c \

	sources/msh_env/msh_env_add_node.c \
	sources/msh_env/msh_env_convert_arr.c \
	sources/msh_env/msh_env_free_list.c \
	sources/msh_env/msh_env_free_node.c \
	sources/msh_env/msh_env_get_node.c \
	sources/msh_env/msh_env_get_value.c \
	sources/msh_env/msh_env_last_node.c \
	sources/msh_env/msh_env_new_list.c \
	sources/msh_env/msh_env_new_node.c \
	sources/msh_env/msh_env_parse_key.c \
	sources/msh_env/msh_env_parse_value.c \

	sources/msh_executor/msh_execute_builtin.c \
	sources/msh_executor/msh_execute_check_builtin.c \
	sources/msh_executor/msh_execute_first.c \
	sources/msh_executor/msh_execute_free_param.c \
	sources/msh_executor/msh_execute_last.c \
	sources/msh_executor/msh_execute_middle.c \
	sources/msh_executor/msh_execute_mktemp.c \
	sources/msh_executor/msh_execute_pipe_shift.c \
	sources/msh_executor/msh_execute_pipeline.c \
	sources/msh_executor/msh_execute_redir_hdoc.c \
	sources/msh_executor/msh_execute_redir.c \
	sources/msh_executor/msh_execute.c \
	sources/msh_executor/msh_exit.c \

	sources/msh_expander/msh_expand_heredoc.c \
	sources/msh_expander/msh_expand.c \
	sources/msh_expander/msh_replace_env.c \
	sources/msh_expander/msh_replace_tokenize.c \
	sources/msh_expander/msh_replace_val.c \
	sources/msh_expander/msh_vqoutes_idx.c \
	sources/msh_expander/msh_vqoutes_num.c \
	sources/msh_expander/msh_vqoutes_tokenize.c \
	sources/msh_expander/msh_vqoutes.c \

	sources/msh_lexer\msh_lex_tokenize_bra.c \
	sources/msh_lexer\msh_lex_tokenize_pipe.c \
	sources/msh_lexer\msh_lex_tokenize_qoutes.c \
	sources/msh_lexer\msh_lex_tokenize_redir.c \
	sources/msh_lexer\msh_lex_tokenize_word.c \
	sources/msh_lexer\msh_lex_tokenize.c \
	sources/msh_lexer\msh_lex.c \

	sources/msh_main/msh_main.c \

	sources/msh_pathfinder/msh_pathfinder_check_path_exist.c \
	sources/msh_pathfinder/msh_pathfinder_find_cmd_abspath.c \
	sources/msh_pathfinder/msh_pathfinder_find_env_path.c \
	sources/msh_pathfinder/msh_pathfinder_is_dir.c \
	sources/msh_pathfinder/msh_pathfinder_is_path.c \
	sources/msh_pathfinder/msh_pathfinder_unset_path.c \
	sources/msh_pathfinder/msh_pathfinder.c \

	sources/msh_pipeline/msh_heredoc_malloc.c \
	sources/msh_pipeline/msh_pipeline_add_heredoc.c \
	sources/msh_pipeline/msh_pipeline_add_node.c \
	sources/msh_pipeline/msh_pipeline_free_list.c \
	sources/msh_pipeline/msh_pipeline_last.c \
	sources/msh_pipeline/msh_pipeline_malloc.c \

	sources/msh_signal/msh_handler.c \
	sources/msh_signal/msh_set_signal.c \
	sources/msh_signal/msh_signal_util.c \

	sources/msh_token/msh_token_add_child.c \
	sources/msh_token/msh_token_add_next.c \
	sources/msh_token/msh_token_add_substr.c \
	sources/msh_token/msh_token_count_sym.c \
	sources/msh_token/msh_token_dequeue.c \
	sources/msh_token/msh_token_filter_sym.c \
	sources/msh_token/msh_token_free_list.c \
	sources/msh_token/msh_token_free_tree.c \
	sources/msh_token/msh_token_free.c \
	sources/msh_token/msh_token_last.c \
	sources/msh_token/msh_token_len_val.c \
	sources/msh_token/msh_token_malloc_sym.c \
	sources/msh_token/msh_token_malloc_symval.c \
	sources/msh_token/msh_token_malloc_val.c \
	sources/msh_token/msh_token_malloc.c \
	sources/msh_token/msh_token_print_list.c \
	sources/msh_token/msh_token_print_tree.c \
	sources/msh_token/msh_token_remove_front.c \
	sources/msh_token/msh_token_union_val.c \

	sources/msh_util/msh_is_charset.c \
	sources/msh_util/msh_is_whitespace.c \
	sources/msh_util/msh_itoa.c \
	sources/msh_util/msh_remove_whitespace.c \
	sources/msh_util/msh_split.c msh_strchr.c \
	sources/msh_util/msh_strcmp.c msh_strcpy.c \
	sources/msh_util/msh_strdup.c msh_strjoin.c \
	sources/msh_util/msh_strlcpy.c msh_strlen.c \
	sources/msh_util/msh_strncpy.c \
	sources/msh_util/msh_substr.c \

MANDATORY_OBJS = $(MANDATORY_SRCS:.c=.o)

.PHONY: all clean fclean re

all: $(NAME)

$(NAME): $(MANDATORY_OBJS)
	@$(CC) $(MANDATORY_OBJS) $(LDFLAGS) -o $(NAME)

%.o : %.c $(HEADERS)
	@$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -Rf $(MANDATORY_OBJS)

fclean: clean
	rm -Rf $(NAME)

re:
	make fclean
	make all
