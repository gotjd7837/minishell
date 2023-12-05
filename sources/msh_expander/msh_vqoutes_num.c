/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   msh_vqoutes_num.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haekang <haekang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 15:36:40 by jho               #+#    #+#             */
/*   Updated: 2023/12/05 19:35:40 by haekang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/msh.h"

int	msh_vqoutes_num(char *s)
{
	int	num;
	int	sqoute_open;
	int	dqoute_open;

	num = 0;
	sqoute_open = 0;
	dqoute_open = 0;
	while (*s != '\0')
	{
		if (*s == '\'' && dqoute_open == 0)
		{
			sqoute_open = !sqoute_open;
			++num;
		}
		else if (*s == '\"' && sqoute_open == 0)
		{
			dqoute_open = !dqoute_open;
			++num;
		}
		++s;
	}
	if (sqoute_open != 0 || dqoute_open != 0)
		return (-1);
	return (num);
}
