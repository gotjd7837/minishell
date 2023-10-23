/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   msh_parse_pipeline.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haeseong <haeseong@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 04:32:25 by haeseong          #+#    #+#             */
/*   Updated: 2023/10/24 04:59:05 by haeseong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int	msh_parse_pipeline(t_token **tokens, t_tree *parent)
{
	t_tree	*node;

	node = msh_parse_new_node(COMMAND);
	if (node == NULL)
		return (0);
	msh_parse_add_child(parent, node);
	if (!msh_parse_command(tokens, node))
		return (0);
	if (msh_accept(tokens, PIPE))
	{
		//pipe가 있다는 거니까 파이프 노드 생성하고 토큰 pop해버리기?
		//pipeline 재귀 호출
	}
	return (1);
}
