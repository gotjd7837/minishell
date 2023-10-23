/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   msh_parse_simple_command_element.c                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haeseong <haeseong@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 05:20:26 by haeseong          #+#    #+#             */
/*   Updated: 2023/10/24 05:28:25 by haeseong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int	msh_parse_simple_command_element(t_token **tokens, t_tree *parent)
{
	t_tree	*node;

	if (msh_accept(tokens, WORD) || msh_accept(tokens, ASSIGNMENT_WORD)
		|| msh_accept(tokens, REDIRECTION))
	{
		node = msh_parse_new_node();//현재 헤드 토큰 심볼
		//헤드 토큰 팝 하기
		//자식 add
	}
	else
		//error
	return (1);
}
