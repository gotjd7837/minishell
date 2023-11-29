/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   msh_execute_mktemp.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jho <jho@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/25 02:23:26 by jho               #+#    #+#             */
/*   Updated: 2023/11/29 16:46:10 by jho              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/msh_executor.h"

char	*msh_execute_mktemp(void)
{
	char	*temp;

	temp = malloc(sizeof(char) * 18);
	if (temp == NULL)
		return (NULL);
	temp[0] = '/';
	temp[1] = 't';
	temp[2] = 'm';
	temp[3] = 'p';
	temp[4] = '/';
	temp[5] = 'm';
	temp[6] = 's';
	temp[7] = 'h';
	temp[8] = '_';
	temp[9] = 'h';
	temp[10] = 'e';
	temp[11] = 'r';
	temp[12] = 'e';
	temp[13] = 'd';
	temp[14] = 'o';
	temp[15] = 'c';
	temp[16] = ' ';
	temp[17] = '\0';
	while (access(temp, 0) == 0)
	{
		if (temp[16] == 126)
		{
			free(temp);
			return (NULL);
		}
		++temp[16];
	}
	return (temp);
}
