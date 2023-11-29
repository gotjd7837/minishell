/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   msh_builtin.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haekang <haekang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/03 19:58:18 by haekang           #+#    #+#             */
/*   Updated: 2023/11/29 17:12:04 by haekang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MSH_BUILTIN_H
# define MSH_BUILTIN_H
# include "msh.h"

int		msh_builtin_cd(int *fd, int pipe, char **cmd, t_env *env);
int		msh_builtin_cd_chdir(char *path, char *old_pwd, int pipe);

int		msh_builtin_echo(int *fd, int pipe, char **cmd, t_env *env);
int		msh_builtin_env(int *fd, int pipe, char **cmd, t_env *env);
int		msh_builtin_exit(int *fd, int pipe, char **cmd, t_env *env);
int		msh_builtin_pwd(int *fd, int pipe, char **cmd, t_env *env);
int		msh_builtin_unset(int *fd, int pipe, char **cmd, t_env *env);

int		msh_builtin_export(int *fd, int pipe, char **cmd, t_env *env);
int		msh_export_print(t_env *env, int out);
int		msh_export_create(char *cmd_arg, t_env *env);
int		msh_is_valid_identifier(char *cmd_arg);
int		msh_check_key(char *cmd_arg);
int		msh_export_key_exist(t_env *env, char *key);

#endif
