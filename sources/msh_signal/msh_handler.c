/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   msh_handler.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haekang <haekang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/01 17:46:22 by haekang           #+#    #+#             */
/*   Updated: 2023/12/06 14:16:30 by haekang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/msh.h"

void	msh_handler_blocking_ctrl_slash(int signum)
{
	(void)signum;
	printf("^\\Quit: 3\n");
	rl_on_new_line();
	rl_replace_line("", 0);
	g_exit_status = 131;
}

void	msh_handler_blocking_ctrl_c(int signum)
{
	(void)signum;
	printf("^C\n");
	rl_on_new_line();
	rl_replace_line("", 0);
	g_exit_status = 130;
}

void	msh_handler_heredoc_ctrl_c(int signum)
{
	(void)signum;
	printf("\n");
	rl_on_new_line();
	rl_replace_line("", 0);
	g_exit_status = 1;
}

void	msh_handler_ctrl_d(int signum)
{
	(void)signum;
	msh_terminal_print_on();
	exit (g_exit_status);
}

void	msh_handler_ctrl_c(int signum)
{
	(void)signum;
	printf("\n");
	rl_on_new_line();
	rl_replace_line("", 0);
	rl_redisplay();
	g_exit_status = 1;
}
