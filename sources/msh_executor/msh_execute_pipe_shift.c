/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   msh_execute_pipe_shift.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jho <jho@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 14:23:35 by jho               #+#    #+#             */
/*   Updated: 2023/11/29 16:17:15 by jho              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/msh_executor.h"

int	msh_execute_pipe_shift(int *fd)
{
	if (close(fd[0]) == -1 || close(fd[1]) == -1)
		return (0);
	if (dup2(fd[2], fd[0]) == -1 || dup2(fd[3], fd[1]) == -1)
		return (0);
	if (close(fd[2]) == -1 || close(fd[3]) == -1)
		return (0);
	return (1);
}
