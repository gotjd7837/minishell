/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   msh_builtin.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haekang <haekang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/03 19:58:18 by haekang           #+#    #+#             */
/*   Updated: 2023/11/07 18:23:45 by haekang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MSH_BUILTIN_H
# define MSH_BUILTIN_H
# include "msh.h"

void	msh_cd(char **cmd, t_env *env);
void	msh_echo(char **cmd);
void	msh_env(t_env *env);
void	msh_exit(char **cmd);
void	msh_pwd(void);
void	msh_unset(t_env *env, char **cmd);

void	msh_export(char **cmd, t_env *env);
int		msh_export_print(t_env *env);
int		msh_export_create(char *cmd_arg, t_env *env);
int		msh_is_valid_identifier(char *cmd_arg);
int		msh_check_key(char *cmd_arg);
int		msh_export_key_exist(t_env *env, char *key);

#endif
