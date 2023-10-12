/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   msh_expand_input.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jho <jho@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/12 12:10:26 by jho               #+#    #+#             */
/*   Updated: 2023/10/12 18:23:47 by jho              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/minishell.h"

char	*msh_expand_input(char *input, t_env *env)
{
	t_comp	*comps;
	char	*expanded_input;

	expanded_input = NULL;
	comps = msh_comp_divide(input);
	if (comps == NULL)
		return (NULL);
	if (!msh_comp_expand(comps, env))
		return ((char *)msh_comp_free(comps));
	expanded_input = msh_comp_union(comps);
	if (expanded_input == NULL)
		return ((char *)msh_comp_free(comps));
	return (expanded_input);
}
