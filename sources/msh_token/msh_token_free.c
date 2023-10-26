/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   msh_token_free.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jho <jho@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 08:53:27 by jho               #+#    #+#             */
/*   Updated: 2023/10/26 08:57:25 by jho              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "msh_token.h"

void	msh_token_free(t_token *token)
{
	if (token == NULL)
		return (NULL);
	if (token->val != NULL)
		free(token->val);
	free(token);
	return (NULL);
}
