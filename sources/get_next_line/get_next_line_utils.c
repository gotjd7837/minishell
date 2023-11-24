/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jho <jho@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/07 16:08:01 by jho               #+#    #+#             */
/*   Updated: 2023/11/25 00:53:26 by jho              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/get_next_line.h"

void	remove_node(t_fd_node **head, int fd)
{
	t_fd_node	*temp;

	if ((*head)->fd == fd)
	{
		temp = *head;
		*head = (*head)->next;
		if (temp->rest != 0)
			free(temp->rest);
		free(temp);
		if (*head != 0)
			(*head)->prev = 0;
	}
	else
	{
		temp = *head;
		while (temp->fd != fd)
			temp = temp->next;
		if (temp->prev != 0)
			temp->prev->next = temp->next;
		if (temp->next != 0)
			temp->next->prev = temp->prev;
		if (temp->rest != 0)
			free(temp->rest);
		free(temp);
	}
}

size_t	ft_gnl_strlen(const char *str)
{
	size_t	len;

	if (str == 0)
		return (0);
	len = 0;
	while (*(str + len) != '\0')
		++len;
	return (len);
}

void	ft_strcpy(char *dest, char *src, size_t len)
{
	size_t	idx;

	if (src == 0)
		return ;
	idx = 0;
	while (idx < len)
	{
		*(dest + idx) = *(src + idx);
		++idx;
	}
}

char	*ft_gnl_strjoin(char *pre, char *pst)
{
	char	*join;
	size_t	prelen;
	size_t	pstlen;

	prelen = ft_gnl_strlen(pre);
	pstlen = ft_gnl_strlen(pst);
	join = (char *)malloc(prelen + pstlen + 1);
	if (join == 0)
		return (0);
	ft_strcpy(join, pre, prelen);
	ft_strcpy(join + prelen, pst, pstlen);
	*(join + prelen + pstlen) = '\0';
	if (pre != 0)
		free(pre);
	return (join);
}

char	*ft_strchr(const char *s, int c)
{
	size_t	idx;
	size_t	len;

	if (s == 0)
		return (0);
	idx = 0;
	len = ft_gnl_strlen(s);
	while (idx <= len)
	{
		if (*(s + idx) == (char)c)
			return ((char *)(s + idx));
		++idx;
	}
	return (0);
}
