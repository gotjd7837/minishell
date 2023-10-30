/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   msh_accept.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jho <jho@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 16:56:14 by jho               #+#    #+#             */
/*   Updated: 2023/10/30 16:57:43 by jho              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/msh_parser.h"

int	msh_accept(t_token *sym_table, t_sym sym)
{
	if (sym_table == NULL)
		return (0);
	return (sym_table->sym == sym);
}
