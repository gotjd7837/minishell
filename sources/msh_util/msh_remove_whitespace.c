/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   msh_remove_whitespace.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jho <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/01 15:38:31 by jho               #+#    #+#             */
/*   Updated: 2023/12/01 15:54:24 by jho              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/msh_util.h"
#include <stdio.h>


char	*msh_remove_whitespace(char *s)
{
	char	*origin;
	char	*removed;

	origin = s;
	while (*s != '\0' && *s == ' ')
		++s;
	removed = msh_strdup(s);
	if (removed == NULL)
		return (NULL);
	free(origin);
	return (removed);
}
