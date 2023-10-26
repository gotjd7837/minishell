/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   msh_expand.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jho <jho@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 09:58:12 by jho               #+#    #+#             */
/*   Updated: 2023/10/26 12:02:10 by jho              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "msh_expander.h"

int	msh_is_in_charset(char c, char *set)
{
	while (*set != '\0')
	{
		if (*set == c)
			return (1);
		++set;
	}
	return (0);
}

int	msh_find_index(char *s, char c)
{
	int	index;

	index = 0;
	while (*(s + index) != '\0')
	{
		if (*(s + index) == c)
			return (index);
		++index;
	}
	return (-1);
}

int	msh_expand_substr_add_next(t_token **tokens, char *s, size_t *range)
{
	char	*val;
	t_token	*token;

	val = msh_substr(s, range[0], range[1]);
	if (val == NULL)
		return (0);
	token = msh_token_malloc_val(val);
	if (token == NULL)
	{
		free(val);
		return (0);
	}
	msh_token_add_next(tokens, token);
	return (1);
}

int	msh_expand_tokenize_lim(t_token **tokens, char *s, size_t *range, char lim)
{
	if (range[0] != range[1])
		if (!msh_expand_substr_add_next(tokens, s, range))
			return (0);
	range[0] = range[1];
	range[1] = msh_find_index(s + range[0], lim) + 1;
	if (range[1] == 0)
		return (0);
	if (!msh_expand_substr_add_next(tokens, s, range))
		return (0);
	range[1] = range[0];
	return (1);
}

t_token	*msh_expand_tokenize(char *s)
{
	t_token		*tokens;
	size_t		range[2];

	range[0] = 0;
	range[1] = 0;
	while (*(s + range[1]) != '\0')
	{
		if (msh_is_in_charset(*(s + range[1]), "\""))
		{
			if (!msh_expand_tokenize_lim(&tokens, s, range, '\"'))
			{
				msh_token_free_list(tokens);
				return (NULL);
			}
		}
		else if (msh_is_in_charset(*(s + range[1]), "\'"))
		{
			if (!msh_expand_tokenize_lim(&tokens, s, range, '\''))
			{
				msh_token_free_list(tokens);
				return (NULL);
			}
		}
		else
			++range[1];
	}
	if (range[0] != range[1])
		if (!msh_expand_substr_add_next(&tokens, s, range))
		{
			msh_token_free_list(tokens);
			return (NULL);
		}
	return (tokens);
}

char	*msh_expand(char *s)
{
	t_token	*tokens;
	char	*expanded;

	tokens = msh_expand_tokenize(s);
	msh_token_print_list(tokens);
	expanded = NULL;
	return (expanded);
}
