# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jho <jho@student.42seoul.kr>               +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/08/25 15:50:06 by jho               #+#    #+#              #
#    Updated: 2023/10/10 12:05:58 by jho              ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
CFLAGS = -Wall -Wextra -Werror
LDFLAGS = -lreadline -lncurses
NAME = minishell
HEADERS = includes/minishell.h
MANDATORY_SRCS = $(wildcard sources/*/*.c)\
				 $(wildcard sources/*/*/*.c)
MANDATORY_OBJS = $(MANDATORY_SRCS:%.c=%.o)

%.o : %.c
	$(CC) $(CFLAGS) -c $< -o $@

all: $(NAME)

$(NAME): $(MANDATORY_OBJS) $(HEADERS)
	$(CC) $(MANDATORY_OBJS) $(LDFLAGS) -o $(NAME)

clean:
	rm -Rf $(MANDATORY_OBJS)

fclean: clean
	rm -Rf $(NAME)

re:
	make fclean
	make all

.PHONY: all clean fclean re
