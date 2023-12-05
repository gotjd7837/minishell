/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   msh_pipeline.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haekang <haekang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 14:44:00 by jho               #+#    #+#             */
/*   Updated: 2023/12/05 18:23:11 by haekang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MSH_PIPELINE_H
# define MSH_PIPELINE_H
# include "msh_token.h"

typedef struct s_heredoc
{
	int					fd;
	char				*name;
	struct s_heredoc	*next;
}	t_heredoc;

typedef struct s_pipeline
{
	t_token				*tokens;
	struct s_pipeline	*next;
	t_heredoc			*heredoc;
	pid_t				pid;
}	t_pipeline;

t_heredoc	*msh_heredoc_malloc(int fd, char *name);
int			msh_pipeline_add_heredoc(t_pipeline *pipeline, t_heredoc *heredoc);
int			msh_pipeline_add_node(t_pipeline **head, t_pipeline *pipeline);
t_pipeline	*msh_pipeline_last(t_pipeline *pipelines);
t_pipeline	*msh_pipeline_free_list(t_pipeline *pipeline);
t_pipeline	*msh_pipeline_malloc(void);
#endif
