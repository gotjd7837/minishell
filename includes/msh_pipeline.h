/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   msh_pipeline.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jho <jho@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 14:44:00 by jho               #+#    #+#             */
/*   Updated: 2023/11/14 15:30:25 by jho              ###   ########.fr       */
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

void		msh_pipeline_add_token(t_pipeline *pipeline, t_token *token);
t_pipeline	*msh_pipeline_free(t_pipeline *pipeline);
t_pipeline	*msh_pipeline_malloc(void);
#endif
