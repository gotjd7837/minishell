/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   msh_util.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haekang <haekang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 11:51:03 by jho               #+#    #+#             */
/*   Updated: 2023/11/03 19:53:50 by haekang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MSH_UTIL_H
# define MSH_UTIL_H
# include <stdlib.h>
# include <unistd.h>

int		msh_is_charset(char c, char *set);
int		msh_is_whitespace(char c);
char	*msh_strchr(char *s, int c);
int		msh_strcmp(char *s1, char *s2);
void	msh_strcpy(char *dest, char *src);
char	*msh_strdup(char *s1);
int		msh_strlen(char *s);
char	*msh_strncpy(char *dest, char *src, size_t n);
char	*msh_substr(char *str, int begin, int end);
char	**msh_split(char *s, char c);
char	*msh_strjoin(char *s1, char *s2);
size_t	msh_strlcpy(char *dst, char *src, size_t dstsize);

#endif
