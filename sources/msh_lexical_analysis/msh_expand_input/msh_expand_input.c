/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   msh_expand_input.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jho <jho@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 12:11:28 by jho               #+#    #+#             */
/*   Updated: 2023/10/10 17:06:38 by jho              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/minishell.h"


void	msh_trim_both_ends(char *value)
{
	int		index;

	index = 1;
	while (*(value + index) != '\0')
	{
		*(value + index - 1) = *(value + index);
		++index;
	}
	*(value + index - 2) = '\0';
}

int	msh_find_env_delimiter(char *value, int index)
{
	while (*(value + index) != '\0' && *(value + index) != ' '
			&& *(value + index) != '$' && *(value + index) != '\"'
			&& *(value + index) != '\'')
		++index;
	return (index);
}

char	*msh_union_comps(t_comp *comps)
{
	char	*str;
	size_t	len;
	t_comp	*cursor;

	str = 0;
	len = 0;
	cursor = comps;
	while (cursor != NULL)
	{
		len += msh_strlen(cursor->value);
		cursor = cursor->next;
	}
	str = malloc(len + 1);
	len = 0;
	while (comps != NULL)
	{
		msh_strncpy(str + len, comps->value, msh_strlen(comps->value));
		len += msh_strlen(comps->value);
		comps = comps->next;
	}
	*(str + len) = '\0';
	return (str);
}

char	*msh_replace_env(char *input)
{
	int		range[2];
	t_comp	*comps;
	t_comp	*cursor;

	range[0] = 0;
	range[1] = 0;
	comps = NULL;
	while (*(input + range[1]) != '\0')
	{
		if (msh_is_dollar(*(input + range[1])))
		{
			msh_add_comp_diff(&comps, input, range[0], range[1]);
			range[0] = range[1];
			range[1] = msh_find_env_delimiter(input, range[0] + 1);
			msh_add_comp(&comps, input, range[0], range[1]);
			range[0] = range[1];
		}
		else
			++range[1];
	}
	msh_add_comp_diff(&comps, input, range[0], range[1]);
	cursor = comps;
	while (cursor != NULL)
	{
		if (msh_is_dollar(*(cursor->value)))
		{
			cursor->value = malloc(3);
			*(cursor->value) = 'a';
			*(cursor->value + 1) = 'b';
			*(cursor->value + 2) = '\0';
		}
		cursor = cursor->next;
	}
	return (msh_union_comps(comps));
}

int	msh_manufacture_comps(t_comp **origin)
{
	t_comp	*comps;

	comps = *origin;
	while (comps != NULL)
	{
		if (msh_is_sqoute(*(comps->value)))
			msh_trim_both_ends(comps->value);
		else if (msh_is_dqoute(*(comps->value)))
		{
			msh_trim_both_ends(comps->value);
			comps->value = msh_replace_env(comps->value);
		}
		else
			comps->value = msh_replace_env(comps->value);
		comps = comps->next;
	}
	return (1);
}

char	*msh_expand_input(char *input)
{
	t_comp	*comps;
	char	*result;

	result = NULL;
	comps = msh_divide_comps(input);
	if (comps == NULL)
		return (NULL);
	msh_manufacture_comps(&comps);
	printf("%s\n", msh_union_comps(comps));
	return (result);
}
