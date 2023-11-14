/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   msh.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haekang <haekang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 12:29:19 by jho               #+#    #+#             */
/*   Updated: 2023/11/14 15:14:37 by jho              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MSH_H
# define MSH_H
# include "msh_expander.h"
# include "msh_lexer.h"
# include "msh_parser.h"
# include "msh_token.h"
# include "msh_pathfinder.h"
# include "msh_builtin.h"
# include "msh_util.h"
# include "msh_pipeline.h"
# include "msh_executor.h"
# include <dirent.h>
# include <term.h>
# include <sys/ioctl.h>
# include <sys/wait.h>
# include <unistd.h>
# include <signal.h>
# include <stdio.h>
# include <stdlib.h>
# include <readline/readline.h>
# include <readline/history.h>

int		g_exit_status;

#endif
