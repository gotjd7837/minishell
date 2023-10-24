/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   msh_parse_list.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haeseong <haeseong@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 21:43:24 by haeseong          #+#    #+#             */
/*   Updated: 2023/10/24 05:20:01 by haeseong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int	msh_parse_list(t_token **tokens, t_tree *parent)
{
	t_tree	*node;

	node = msh_parse_new_node(PIPELINE);
	if (node == NULL)
		return (0);
	msh_parse_add_child(parent, node);
	if (!msh_parse_pipeline(tokens, node))
		return (0);
	if (msh_accept(tokens, AND_IF) || msh_accept(tokens, OR_IF))
	{
		//AND_IF가 있다는 거니까 노드 생성하고 토큰 pop해버리기?
		//list 재귀 호출
		//헤드 토큰 팝하는 함수 구현하기
	}
	return (1);
}
