/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsegovia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/21 10:15:13 by jsegovia          #+#    #+#             */
/*   Updated: 2022/02/21 10:15:17 by jsegovia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static void ft_read (int fd, char *buffer, char **str)
{
	int		count;
	char	*tmp;

	if (!*str || !ft_strchr(*str, '\n'))
	{
		count = read(fd, buffer, BUFFER_SIZE);
		while (count > 0)
		{
			buffer[count] = 0;
			if (!*str)
				*str = ft_substr(buffer, 0, count);
			else
			{
				tmp = *str;
				*str = ft_strjoin(*str, buffer);
				free(tmp);
			}
			if (ft_strchr(buffer, '\n'))
				break ;
			count = read(fd, buffer, BUFFER_SIZE);
		}
	}
	free(buffer);
}

static char ft_process(char **str)
{
	char	*res;
	char	*temp;
	size_t	count;
	size_t	counter;

	if(!str)
		return(0);
	if (!ft_strchr(*str, '\n'))
	{
		res = ft_substr(*str, 0, ft_strlen(*str));
		free(*str);
		*str = 0;
		return (res);
	}
	count = ft_strlen(*str);
	counter = ft_strlen(ft_strchr(*str, '\n'));
	res = ft_substr(*str, 0, count - counter + 1);
	temp = *str;
	*str = ft_substr(ft_strchr(*str, '\n'), 1, counter - 1);
	free(temp);
	return (res);
}

char	*get_next_line(int fd)
{
	static char	*str;
	char		buffer;

	buffer = malloc(sizeof(char) * (BUFFER_SIZE + 1));	//Create and check memory buffer
	if (!buffer)
		return (0);
	if (BUFFER_SIZE < 1 || fd == -1 || read(fd, buffer, 0) == -1)	//Check if buffer doesn't have viable size, fd isn't valid or cannot load read files
	{
		free(buffer);
		return (0);
	}
	ft_read(fd, &buffer, &str);
	return (ft_process(&str));
}
