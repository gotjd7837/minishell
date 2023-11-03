/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   msh_env.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haekang <haekang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/27 19:58:03 by jho               #+#    #+#             */
/*   Updated: 2023/11/03 19:52:33 by haekang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MSH_ENV_H
# define MSH_ENV_H
# include "msh_util.h"

typedef struct s_env
{
	char			*key;
	char			*value;
	struct s_env	*next;
	struct s_env	*prev;
}	t_env;

int		msh_env_add_node(t_env **list, char *envp);
t_env	*msh_env_free_list(t_env *list);
t_env	*msh_env_free_node(t_env *node);
t_env	*msh_env_get_node(t_env *env, char *key);
char	*msh_env_get_value(t_env *env, char *key);
t_env	*msh_env_last_node(t_env *list);
t_env	*msh_env_new_list(char *envp[]);
int		msh_env_new_node(t_env **node);
char	*msh_env_parse_key(char *envp);
char	*msh_env_parse_value(char *envp);

#endif
