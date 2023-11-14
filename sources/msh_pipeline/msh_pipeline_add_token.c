/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   msh_pipeline_add_token.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jho <jho@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 14:31:28 by jho               #+#    #+#             */
/*   Updated: 2023/11/14 14:38:10 by jho              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/msh_pipeline.h"

void	msh_pipeline_add_token(t_pipeline *pipeline, t_token *token)
{
	if (pipeline == NULL || token == NULL) return ;
	msh_token_add_next(&(pipeline->tokens), token);
}
