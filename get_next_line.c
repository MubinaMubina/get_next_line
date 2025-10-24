/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmubina <mmubina@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/23 20:07:45 by mmubina           #+#    #+#             */
/*   Updated: 2025/10/24 16:58:36 by mmubina          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*_fill_line_buffer(int fd, char *left_c, char *buffer);
static char	*_set_line(char *line);
char		*ft_strchr(char *s, int c);

char	*get_next_line(int fd)
{
	static char	*remainder;
	char		*buffer;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	buffer = malloc(BUFFER_SIZE + 1);
	if (!buffer)
		return (NULL);
	remainder = _fill_line_buffer(fd, remainder, buffer);
	free(buffer);
	if (!remainder)
		return (NULL);
	line = ft_strdup(remainder);
	if (!line)
	{
		free(remainder);
		remainder = NULL;
		return (NULL);
	}
	remainder = _set_line(remainder);
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

static char	*_set_line(char *line_buffer)
{
	int		i;
	char	*remainder;

	i = 0;
	while (line_buffer[i] != '\0' && line_buffer[i] != '\n')
		i++;
	if (line_buffer[i] == '\n')
	{
		remainder = ft_substr(line_buffer, i + 1, ft_strlen(line_buffer) - (i
					+ 1));
		line_buffer[i + 1] = '\0';
		free(line_buffer);
		return (remainder);
	}
	free(line_buffer);
	return (NULL);
}
