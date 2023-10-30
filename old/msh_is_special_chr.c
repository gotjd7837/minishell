/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   msh_is_special_chr.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jho <jho@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/12 16:56:17 by jho               #+#    #+#             */
/*   Updated: 2023/10/12 18:26:42 by jho              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	msh_is_special_chr(char c)
{
	return (c == '$' || c == ' ' || c == '\"' || c == '\''
		|| c == '|' || c == '&' || c == '\0');
}