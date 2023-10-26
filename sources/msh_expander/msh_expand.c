/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   msh_expand.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jho <jho@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 09:58:12 by jho               #+#    #+#             */
/*   Updated: 2023/10/26 15:41:48 by jho              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/msh_expander.h"

char	*msh_expand(char *s)
{
	t_token	*tokens;
	char	*expanded;

	tokens = msh_vqoutes(s);
	msh_token_print_list(tokens);
	msh_token_free_list(tokens);
	expanded = NULL;
	return (expanded);
}
