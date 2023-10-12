/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   msh_strtrim_bothends.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jho <jho@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/12 16:43:55 by jho               #+#    #+#             */
/*   Updated: 2023/10/12 16:45:12 by jho              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	msh_strtrim_bothends(char *input)
{
	int	index;

	index = 1;
	while (*(input + index) != '\0')
	{
		*(input + index - 1) = *(input + index);
		++index;
	}
	*(input + index - 2) = '\0';
}
