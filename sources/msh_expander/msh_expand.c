/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   msh_expand.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jho <jho@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 09:58:12 by jho               #+#    #+#             */
/*   Updated: 2023/10/27 21:10:52 by jho              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/msh_expander.h"

char	*msh_expand(char *s, t_env *env)
{
	t_token	*tokens;
	char	*expanded;

	tokens = msh_vqoutes(s);
	msh_replace_env(&tokens, env);
	expanded = msh_token_union_val(tokens);
	msh_token_free_list(tokens);
	return (expanded);
}
