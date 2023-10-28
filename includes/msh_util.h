/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   msh_util.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jho <jho@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 11:51:03 by jho               #+#    #+#             */
/*   Updated: 2023/10/28 08:49:05 by jho              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MSH_UTIL_H
# define MSH_UTIL_H
# include <stdlib.h>

int		msh_is_charset(char c, char *set);
int		msh_is_whitespace(char c);
char	*msh_strchr(char *s, int c);
int		msh_strcmp(char *s1, char *s2);
void	msh_strcpy(char *dest, char *src);
char	*msh_strdup(char *s1);
int		msh_strlen(char *s);
char	*msh_strncpy(char *dest, char *src, size_t n);
char	*msh_substr(char *str, int begin, int end);
#endif
