/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   msh_executor.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jho <jho@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 15:00:43 by jho               #+#    #+#             */
/*   Updated: 2023/11/14 15:12:16 by jho              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MSH_EXECUTOR_H
# define MSH_EXECUTOR_H
# include "msh_token.h"
# include "msh_pipeline.h"
# include "msh_env.h"
# include "msh_pathfinder.h"

int	msh_execute(t_pipeline *pipeline, t_env *env);
#endif
