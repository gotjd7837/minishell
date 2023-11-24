/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   msh_execute_mktemp.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jho <jho@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/25 02:23:26 by jho               #+#    #+#             */
/*   Updated: 2023/11/25 03:11:17 by jho              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/msh_executor.h"

char	*msh_execute_mktemp(void)
{
	char	*temp;

	temp = malloc(sizeof(char) * 9);
	if (temp == NULL)
		return (NULL);
	temp[0] = 'H';
	temp[1] = 'E';
	temp[2] = 'R';
	temp[3] = 'E';
	temp[4] = 'D';
	temp[5] = 'O';
	temp[6] = 'C';
	temp[7] = ' ';
	temp[8] = '\0';
	while (access(temp, 0) == 0)
	{
		if (temp[7] == 126)
		{
			free(temp);
			return (NULL);
		}
		++temp[7];
	}
	return (temp);
}
