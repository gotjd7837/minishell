/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   msh_execute_pipe_shift.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jho <jho@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 14:23:35 by jho               #+#    #+#             */
/*   Updated: 2023/11/25 04:10:04 by jho              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/msh_executor.h"

int	msh_execute_pipe_shift(int *fd)
{
	close(fd[0]);
	close(fd[1]);
	dup2(fd[2], fd[0]);
	dup2(fd[3], fd[1]);
	close(fd[2]);
	close(fd[3]);
	return (1);
}
