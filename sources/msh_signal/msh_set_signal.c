/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   msh_set_signal.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haekang <haekang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 17:58:05 by haekang           #+#    #+#             */
/*   Updated: 2023/12/05 19:37:48 by haekang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/msh.h"

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
