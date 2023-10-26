/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   msh_util.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jho <jho@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 11:51:03 by jho               #+#    #+#             */
/*   Updated: 2023/10/26 14:59:18 by jho              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MSH_UTIL_H
# define MSH_UTIL_H
# include <stdlib.h>

void	msh_strcpy(char *dest, char *src);
int		msh_strlen(char *s);
char	*msh_substr(char *str, int begin, int end);
#endif
