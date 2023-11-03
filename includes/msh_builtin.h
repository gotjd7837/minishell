/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   msh_builtin.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haekang <haekang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/03 19:58:18 by haekang           #+#    #+#             */
/*   Updated: 2023/11/03 20:10:50 by haekang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MSH_BUILTIN_H
# define MSH_BUILTIN_H
# include "msh.h"

void	msh_cd(char **cmd, t_env *env);
void	msh_echo(char **cmd);
void	msh_env(t_env *env);
void	msh_exit(char **cmd);
void	msh_export(char **cmd, t_env *env);
void	msh_pwd(void);
void	msh_unset(t_env *env, char **cmd);

#endif
