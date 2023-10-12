/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   msh_validate_qoute.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jho <jho@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 12:13:18 by jho               #+#    #+#             */
/*   Updated: 2023/10/12 12:11:37 by jho              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/minishell.h"

int	msh_validate_dqoute(char *input, int index)
{
	while (!msh_is_dqoute(*(input + index)))
	{
		if (*(input + index) == '\0')
			return (-1);
		++index;
	}
	return (index);
}

int	msh_validate_sqoute(char *input, int index)
{
	while (!msh_is_sqoute(*(input + index)))
	{
		if (*(input + index) == '\0')
			return (-1);
		++index;
	}
	return (index);
}

int	(*msh_get_validator(char c))(char *input, int index)
{
	if (msh_is_sqoute(c))
		return (&msh_validate_sqoute);
	else if (msh_is_dqoute(c))
		return (&msh_validate_dqoute);
	else
		return (NULL);
}
