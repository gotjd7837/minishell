/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   msh_vqoutes_num.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jho <jho@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 15:36:40 by jho               #+#    #+#             */
/*   Updated: 2023/10/26 15:37:04 by jho              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	msh_vqoutes_num(char *s)
{
	int	num;
	int	sqoute_open;
	int	dqoute_open;

	num = 0;
	sqoute_open = 0;
	dqoute_open = 0;
	while (*s != '\0')
	{
		if (*s == '\'' && dqoute_open == 0)
		{
			sqoute_open = !sqoute_open;
			++num;
		}
		else if (*s == '\"' && sqoute_open == 0)
		{
			dqoute_open = !dqoute_open;
			++num;
		}
		++s;
	}
	if (sqoute_open != 0 || dqoute_open != 0)
		return (-1);
	return (num);
}
