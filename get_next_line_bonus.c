/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsegovia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/01 12:53:28 by jsegovia          #+#    #+#             */
/*   Updated: 2022/03/01 12:53:40 by jsegovia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"
//#include <stdio.h>
//#include <fcntl.h>

static void	ft_read(int fd, char *buffer, char **str)
{
	int		count;
	char	*temp;

	if (!str[fd] || !ft_strchr(str[fd], '\n'))
	{
		count = read(fd, buffer, BUFFER_SIZE);
		while (count > 0)
		{
			buffer[count] = 0;
			if (!str[fd])
				str[fd] = ft_substr(buffer, 0, count);
			else
			{
				temp = str[fd];
				str[fd] = ft_strjoin(str[fd], buffer);
				free(temp);
			}
			if (ft_strchr(buffer, '\n'))
				break ;
			count = read(fd, buffer, BUFFER_SIZE);
		}
	}
	free(buffer);
}

static char	*ft_processing(int fd, char **str)
{
	size_t	count;
	size_t	counter;
	char	*res;
	char	*temp;

	if (!str[fd])
		return (0);
	if (!ft_strchr(str[fd], '\n'))
	{
		res = ft_substr(str[fd], 0, ft_strlen(str[fd]));
		free(str[fd]);
		str[fd] = 0;
		return (res);
	}
	count = ft_strlen(str[fd]);
	counter = ft_strlen(ft_strchr(str[fd], '\n'));
	res = ft_substr(str[fd], 0, count - counter + 1);
	temp = str[fd];
	str[fd] = ft_substr(ft_strchr(str[fd], '\n'), 1, counter - 1);
	free(temp);
	return (res);
}

char	*get_next_line(int fd)
{
	static char	*str[OPEN_MAX];
	char		*buffer;

	buffer = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buffer)
		return (0);
	if (BUFFER_SIZE < 1 || fd == -1 || read(fd, buffer, 0) == -1)
	{
		free(buffer);
		return (0);
	}
	ft_read(fd, buffer, str);
	return (ft_processing(fd, str));
}

/*
int	main(void)
{
	int		fd;
	char	*res;

	fd = open("tests/41_no_nl", O_RDWR);
	res = get_next_line(fd);
	if (!res)
		return (printf("\nTest Failed"));
	else
		return (printf("\nTest Success: %s", res));
}*/

/*
20	: Check if str is valid or doesn't have end char
22	: Get the amount of characters to populate the str with from reading fd
26	: If the str doesn't exist; populate it with the contents of the buffer
28	: If the str exists, add the buffer ot it
34	: If the buffer has end char exit the loop
36	: Reset the loop with another count of the characters in fd

51	: Check if line has end char
54	: Populate res with the content of str; then free str and return res
58	: Get total str lenght 
59	: Get the length from the first end char found till the end
60	: Make a substr from str, starting at 0, untill the first end char
61	: Create a reference to str
62	: Cut from the str from start till the end char found

72	: Create and check memory buffer
75	: Check if buffer doesn't have viable size, 
	  if fd isn't valid or cannot read files
*/
