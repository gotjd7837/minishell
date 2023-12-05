/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   msh_execute_pipe_shift.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haekang <haekang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 14:23:35 by jho               #+#    #+#             */
/*   Updated: 2023/12/05 19:34:31 by haekang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/msh.h"

int	msh_execute_pipe_shift(int *fd, int *local_fd)
{
	if (fd[0] != local_fd[0])
		close(local_fd[0]);
	if (fd[1] != local_fd[1])
		close(local_fd[1]);
	close(fd[0]);
	close(fd[1]);
	fd[0] = fd[2];
	fd[1] = fd[3];
	return (1);
}
