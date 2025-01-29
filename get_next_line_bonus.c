/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: axlleres <axlleres@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 17:17:57 by axlleres          #+#    #+#             */
/*   Updated: 2025/01/16 17:20:29 by axlleres         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <unistd.h>
#include <stdlib.h>

char	*get_next_line(int fd)
{
	static char	*rest[0xfff] = {NULL};
	char		*line;
	int			len;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	if (read_enough(fd, &(rest[fd])) == -1)
	{
		free(rest[fd]);
		rest[fd] = NULL;
		return (NULL);
	}
	if (rest[fd] == NULL || *(rest[fd]) == '\0')
	{
		free(rest[fd]);
		return (rest[fd] = NULL, NULL);
	}
	len = ft_strchr(rest[fd], '\n');
	if (len == -1)
		line = malloc(ft_strchr(rest[fd], '\0') + 3);
	else
		line = malloc(len + 3);
	ft_strcpy_to_c(rest[fd], line, '\n');
	str_shift_c(&(rest[fd]), '\n');
	return (line);
}
