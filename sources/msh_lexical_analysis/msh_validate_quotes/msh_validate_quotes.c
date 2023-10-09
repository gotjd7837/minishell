/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   msh_validate_quotes.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jho <jho@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 10:42:27 by jho               #+#    #+#             */
/*   Updated: 2023/10/09 12:45:32 by jho              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	msh_is_squote(char c)
{
	return (c == '\'');
}

int	msh_is_dquote(char c)
{
	return (c == '\"');
}

int	msh_validate_quotes(char *input)
{
	while (*input != '\0')
	{
		if (msh_is_squote(*input))
			while (!msh_is_squote(*(++input)))
				if (*input == '\0')
					return (0);
		if (msh_is_dquote(*input))
			while (!msh_is_dquote(*(++input)))
				if (*input == '\0')
					return (0);
		++input;
	}
	return (1);
}
