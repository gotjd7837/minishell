/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   msh_main.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haekang <haekang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/25 16:14:20 by jho               #+#    #+#             */
/*   Updated: 2023/10/10 15:13:47 by haekang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

typedef struct s_env
{
    char            *key;
    char            *value;
    struct s_env    *next;
}   t_env;

char    *msh_get_value(char *str)
{
    int     end_idx;
    int     equal_idx;
    char    *value;

    end_idx = 0;
    equal_idx = 0;
    while (str[end_idx])
    {
        if (str[end_idx] == '=')
            equal_idx = end_idx;
        end_idx++;
    }
    value = msh_substr(str, (equal_idx + 1), end_idx);
    if (value == NULL)
        return (NULL);
    return (value);
}

char    *msh_get_key(char *str)
{
    int     i;
    int     equal_idx;
    char    *key;

    i = 0;
    equal_idx = 0;
    while (str[equal_idx])
    {
        if (str[equal_idx] == '=')
            break ;
        equal_idx++;
    }
    key = msh_substr(str, 0, equal_idx);
    if (key == NULL)
        return (NULL);
    return (key);
}

// int  msh_strchr(const char *s, int c)
// {
//  int i;

//  i = 0;
//  if ((unsigned char)c == '\0')
//      return (-1);
//  while (s[i])
//  {
//      if (s[i] == (unsigned char)c)
//          return (i);
//      i++;
//  }
//  return (-1);
// }

t_env   *msh_new_node(char *key, char *value)
{
    t_env   *node;

    node = (t_env *)malloc(sizeof(t_env));
    if (node == NULL)
        return (NULL);
    node->key = key;
    node->value = value;
    node->next = NULL;
    return (node);
}

void    msh_env_lstadd(t_env **envp_list, char *envp)
{
    t_env   *node;
    char    *key;
    char    *value;

    node = *envp_list;
    key = msh_get_key(envp);
    value = msh_get_value(envp);
    while (node->next != NULL)
        node = node->next;
    node->next = msh_new_node(key, value);
}

int	msh_envp_preprocess(char **envp, t_env **envp_list)
{
	int		i;
	char	*key;
	char	*value;

	i = 0;
	while (envp[i] == NULL)
	{
		if (i == 0)
		{
			key = msh_get_key(envp[i]);
			value = msh_get_value(envp[i]);
			*envp_list = msh_new_node(key, value);
		}
		else
			msh_env_lstadd(envp_list, envp[i]);
		i++;
	}
}

int main(int ac, char **av, char **envp)
{
    char    *input;
    t_env   *envp_list;
    t_token *tokens;

    (void)ac;
    (void)av;
    if (msh_envp_preprocess(envp, &envp_list))
        return (1);
    while (1)
    {
        input = readline("minishell$ ");
        tokens = msh_lexical_analysis(input);
        add_history(input);
        msh_print_tokens(tokens);
        free(input);
    }
    return (0);
}
sfsdf