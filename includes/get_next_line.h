/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haekang <haekang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/21 03:44:03 by jho               #+#    #+#             */
/*   Updated: 2023/12/05 19:31:34 by haekang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# include <stdlib.h>
# include <unistd.h>
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1024
# endif

typedef struct s_fd_node
{
	int					fd;
	char				*rest;
	struct s_fd_node	*parent;
	struct s_fd_node	*prev;
	struct s_fd_node	*next;
}	t_fd_node;

char	*get_next_line(int fd);
size_t	ft_gnl_strlen(const char *s);
void	ft_strcpy(char *dest, char *src, size_t len);
char	*ft_gnl_strjoin(char *pre, char *pst);
char	*ft_strchr(const char *s, int c);
char	*mfree(char **p1, char *p2, t_fd_node **head, int fd);
void	remove_node(t_fd_node **head, int fd);
#endif
