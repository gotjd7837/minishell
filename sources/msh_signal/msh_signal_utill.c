/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   msh_signal_utill.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haekang <haekang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/01 17:47:19 by haekang           #+#    #+#             */
/*   Updated: 2023/12/05 19:37:51 by haekang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/msh.h"

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
