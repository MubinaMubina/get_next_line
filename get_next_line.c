/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmubina <mmubina@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/23 20:07:45 by mmubina           #+#    #+#             */
/*   Updated: 2025/10/24 16:05:55 by mmubina          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static char	*remainder;
	char		*buffer;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	if (read(fd, 0, 0) < 0)
		return (NULL);
	buffer = malloc(BUFFER_SIZE + 1);
	if (!buffer)
		return (NULL);
	remainder = _fill_line_buffer(fd, remainder, buffer);
	if (!remainder)
	{
		free(remainder);
		return (NULL);
	}
	line = _set_line(remainder);
	free(buffer);
	return (line);
}

static char	*_fill_line_buffer(int fd, char *remainder, char *buffer)
{
	ssize_t	bytes_read;
	char	*newline_found;

	newline_found = NULL;
	bytes_read = read(fd, buffer, BUFFER_SIZE);
	while (!newline_found && bytes_read > 0)
	{
		buffer[bytes_read] = '\0';
		if (remainder == NULL)
			remainder = ft_strdup(buffer);
		else
			remainder = ft_strjoin(remainder, buffer);
		newline_found = ft_strchr(remainder, '\n');
		if (newline_found)
			break ;
		bytes_read = read(fd, buffer, BUFFER_SIZE);
	}
	return (remainder);
}

char	*_set_line(char *line_buffer)
{
	int		i;
	char	*remainder;

	i = 0;
	while (line_buffer[i] != '\0' && line_buffer[i] != '\n')
		i++;
	if (line_buffer[i] == '\n')
	{
		remainder = ft_substr(line_buffer, (i + 1), ft_strlen(line_buffer + i
					+ 1));
		line_buffer[i + 1] = '\0';
	}
	return (remainder);
}
