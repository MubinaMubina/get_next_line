/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmubina <mmubina@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/27 22:52:54 by mmubina           #+#    #+#             */
/*   Updated: 2025/10/28 00:10:50 by mmubina          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

static char	*_fill_line_buffer(int fd, char *remainder, char *buffer);
static char	*_set_line(char *line_buffer);
static char	*extract_line(char *remainder);

char	*get_next_line(int fd)
{
	static char	*remainder[1024];
	char		*buffer;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	buffer = malloc(BUFFER_SIZE + 1);
	if (!buffer)
		return (NULL);
	remainder[fd] = _fill_line_buffer(fd, remainder[fd], buffer);
	free(buffer);
	if (!remainder)
		return (NULL);
	line = extract_line(remainder[fd]);
	if (!line)
	{
		free(remainder[fd]);
		remainder[fd] = NULL;
		return (NULL);
	}
	remainder[fd] = _set_line(remainder[fd]);
	return (line);
}

static char	*_fill_line_buffer(int fd, char *rem, char *buf)
{
	ssize_t	bytes_read;

	if (rem && ft_strchr(rem, '\n'))
		return (rem);
	bytes_read = read(fd, buf, BUFFER_SIZE);
	while (bytes_read > 0)
	{
		buf[bytes_read] = '\0';
		rem = ft_strjoin(rem, buf);
		if (!rem || ft_strchr(rem, '\n'))
			break ;
		bytes_read = read(fd, buf, BUFFER_SIZE);
	}
	if (bytes_read < 0)
	{
		free(rem);
		rem = NULL;
		return (NULL);
	}
	return (rem);
}

static char	*_set_line(char *line_buffer)
{
	int		i;
	char	*new_remainder;

	if (!line_buffer)
		return (NULL);
	i = 0;
	while (line_buffer[i] && line_buffer[i] != '\n')
		i++;
	if (line_buffer[i] == '\n')
		i++;
	if (!line_buffer[i])
	{
		free(line_buffer);
		return (NULL);
	}
	new_remainder = ft_strdup(line_buffer + i);
	free(line_buffer);
	return (new_remainder);
}

static char	*extract_line(char *remainder)
{
	int		i;
	char	*line;

	if (!remainder)
		return (NULL);
	i = 0;
	while (remainder[i] && remainder[i] != '\n')
		i++;
	if (remainder[i] == '\n')
		i++;
	line = malloc(i + 1);
	if (!line)
		return (NULL);
	line[i] = '\0';
	while (i-- > 0)
		line[i] = remainder[i];
	return (line);
}
