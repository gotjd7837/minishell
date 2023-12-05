/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   msh_heredoc_malloc.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haekang <haekang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 15:21:13 by jho               #+#    #+#             */
/*   Updated: 2023/12/05 19:37:22 by haekang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/msh.h"

t_heredoc	*msh_heredoc_malloc(int fd, char *name)
{
	t_heredoc	*heredoc;

	heredoc = (t_heredoc *)malloc(sizeof(t_heredoc));
	if (heredoc == NULL)
		return (NULL);
	heredoc->fd = fd;
	heredoc->name = name;
	heredoc->next = NULL;
	return (heredoc);
}
