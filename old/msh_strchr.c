/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   msh_strchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jho <jho@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 11:41:27 by jho               #+#    #+#             */
/*   Updated: 2023/10/17 11:45:07 by jho              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

char	*msh_strchr(char *s, int c)
{
	size_t	index;
	size_t	len;

	index = 0;
	len = msh_strlen(s);
	while (index <= len)
	{
		if (*(s + index) == (char)c)
			return ((char *)(s + index));
		++index;
	}
	return (0);
}
