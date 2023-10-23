/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   msh_accept.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haeseong <haeseong@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 21:01:02 by haeseong          #+#    #+#             */
/*   Updated: 2023/10/23 21:07:34 by haeseong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int	msh_accept(t_token **tokens, t_symbol symbol)
{
	if ((*tokens)->symbol == symbol)
		return (1);
	return (0);
}
