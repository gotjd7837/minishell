/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   msh_remove_whitespace.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haekang <haekang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/01 15:38:31 by jho               #+#    #+#             */
/*   Updated: 2023/12/05 19:39:51 by haekang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/msh.h"

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
