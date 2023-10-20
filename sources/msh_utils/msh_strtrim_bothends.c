/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   msh_strtrim_bothends.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haekang <haekang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/12 16:43:55 by jho               #+#    #+#             */
/*   Updated: 2023/10/20 15:39:09 by haekang          ###   ########.fr       */
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
