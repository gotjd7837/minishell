/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   msh_expand_input.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jho <jho@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/12 12:10:26 by jho               #+#    #+#             */
/*   Updated: 2023/10/12 13:38:52 by jho              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/minishell.h"

void	msh_trim_bothends(char *input)
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

int	msh_find_delimiter(char *input, int index)
{
	while (*(input + index) != '$' && *(input + index) != ' ' && *(input + index) != '\"'
			&& *(input + index) != '\'' && *(input + index) != '|' && *(input + index) != '&'
			&& *(input + index) != '\0')
		++index;
	return (index);
}

char	*msh_expand_env(char *input)
{
	int		range[2];
	char	*result;
	t_comp	*comps;
	t_comp	*comps_2;

	range[0] = 0;
	range[1] = 0;
	comps = 0;
	while (*(input + range[1]) != '\0')
	{
		if (msh_is_dollar(*(input + range[1])))
		{
			msh_add_comp_diff(&comps, input, range[0], range[1]);
			range[0] = range[1];
			range[1] = msh_find_delimiter(input, range[0] + 1);
			msh_add_comp(&comps, input, range[0], range[1]);
			range[0] = range[1];
		}
		else
			++range[1];
	}
	msh_add_comp_diff(&comps, input, range[0], range[1]);
	comps_2 = comps;
	while (comps_2 != NULL)
	{
		if(msh_is_dollar(*(comps_2->value)))
		{
			*(comps_2->value) = 'a';
			*(comps_2->value + 1) = '\0';
		}
		comps_2 = comps_2->next;
	}
	int len = 0;
	len = 0;
	comps_2 = comps;
	while (comps_2 != NULL)
	{
		len += msh_strlen(comps_2->value);
		comps_2 = comps_2->next;
	}
	result = malloc(len + 1);
	len = 0;
	while (comps != NULL)
	{
		msh_strncpy(result + len, comps->value, msh_strlen(comps->value));
		len += msh_strlen(comps->value);
		comps = comps->next;
	}
	*(result + len) = '\0';
	return (result);
}

char	*msh_union_comps(t_comp *origin)
{
	int		len;
	t_comp	*comps;
	char	*result;

	comps = origin;
	while (comps != NULL)
	{
		if (msh_is_sqoute(*(comps->value)))
			msh_trim_bothends(comps->value);
		else if (msh_is_dqoute(*(comps->value)))
		{
			msh_trim_bothends(comps->value);
			comps->value = msh_expand_env(comps->value);
		}
		else
			comps->value = msh_expand_env(comps->value);
		comps = comps->next;
	}
	len = 0;
	comps = origin;
	while (comps != NULL)
	{
		len += msh_strlen(comps->value);
		comps = comps->next;
	}
	result = malloc(len + 1);
	len = 0;
	while (origin != NULL)
	{
		msh_strncpy(result + len, origin->value, msh_strlen(origin->value));
		len += msh_strlen(origin->value);
		origin = origin->next;
	}
	*(result + len) = '\0';
	return (result);
}

char	*msh_expand_input(char *input)
{
	t_comp	*comps;
	char	*result;

	result = NULL;
	comps = msh_divide_comps(input);
	if (comps == NULL)
		printf("Syntax Error\n");
	result = msh_union_comps(comps);
	printf("%s\n", result);
	return (result);
}
