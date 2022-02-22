/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsegovia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/21 10:15:21 by jsegovia          #+#    #+#             */
/*   Updated: 2022/02/21 10:15:32 by jsegovia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

#ifndef BUFFER_SIZE
# define BUFFER_SIZE 42
# endif

# include <stdlib.h>
# include <unistd.h>
# include <sys/errno.h>

char	*get_next_line(int fd);

char *ft_strchr(const char *s, int c)
char *ft_strjoin(char const *s1, char const *s2)
size_t ft_strlen(const char *s)
char *ft_substr(char const *s, unsigned int start, size_t len)

#endif