/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   msh_signal.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haekang <haekang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 17:58:05 by haekang           #+#    #+#             */
/*   Updated: 2023/12/01 16:36:09 by haekang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/msh_signal.h"

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

void	msh_handler_ctrl_c(int signum)
{
	(void)signum;
	printf("\n");
	rl_on_new_line();
	rl_replace_line("", 0);
	rl_redisplay();
	g_exit_status = 1;
}

void	msh_terminal_print_off(void)
{
	struct termios	term;

	tcgetattr(1, &term);
	term.c_lflag &= ~(ECHOCTL);
	tcsetattr(1, 0, &term);
}

void	msh_terminal_print_on(void)
{
	struct termios	term;

	tcgetattr(1, &term);
	term.c_lflag |= (ECHOCTL);
	tcsetattr(1, 0, &term);
}

void	msh_set_default_signal(void)
{
	signal(SIGINT, SIG_DFL);
	signal(SIGQUIT, SIG_DFL);
}

void	msh_set_blocking_signal(void)
{
	signal(SIGINT, msh_handler_blocking_ctrl_c);
	signal(SIGQUIT, msh_handler_blocking_ctrl_slash);
}

void	msh_set_signal(void)
{
	msh_terminal_print_off();
	signal(SIGINT, msh_handler_ctrl_c);
	signal(SIGQUIT, SIG_IGN);
}
