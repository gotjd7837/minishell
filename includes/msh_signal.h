/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   msh_signal.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haekang <haekang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 17:58:16 by haekang           #+#    #+#             */
/*   Updated: 2023/12/01 17:50:26 by haekang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MSH_SIGNAL_H
# define MSH_SIGNAL_H
# include "msh.h"
# include <signal.h>

void	msh_set_signal(void);
void	msh_set_blocking_signal(void);
void	msh_set_default_signal(void);

void	msh_handler_ctrl_c(int signum);
void	msh_handler_heredoc_ctrl_c(int signum);
void	msh_handler_blocking_ctrl_c(int signum);
void	msh_handler_blocking_ctrl_slash(int signum);

void	msh_terminal_print_on(void);
void	msh_terminal_print_off(void);

#endif