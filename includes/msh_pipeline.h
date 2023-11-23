/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   msh_pipeline.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haekang <haekang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 14:44:00 by jho               #+#    #+#             */
/*   Updated: 2023/11/23 15:59:51 by haekang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MSH_PIPELINE_H
# define MSH_PIPELINE_H
# include "msh_token.h"

typedef struct s_pipeline
{
	t_token				*tokens;
	struct s_pipeline	*next;
}	t_pipeline;

int			msh_pipeline_add_node(t_pipeline **head, t_pipeline *pipeline);
t_pipeline	*msh_pipeline_last(t_pipeline *pipelines);
t_pipeline	*msh_pipeline_free_list(t_pipeline *pipeline);
t_pipeline	*msh_pipeline_malloc(void);
#endif
