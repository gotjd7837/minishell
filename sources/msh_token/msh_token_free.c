/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   msh_token_free.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haekang <haekang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 08:53:27 by jho               #+#    #+#             */
/*   Updated: 2023/12/05 19:38:41 by haekang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/msh.h"

t_token	*msh_token_free(t_token *token)
{
	if (token == NULL)
		return (NULL);
	if (token->val != NULL)
		free(token->val);
	free(token);
	return (NULL);
}
