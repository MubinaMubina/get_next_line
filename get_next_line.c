/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmubina <mmubina@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/23 20:07:45 by mmubina           #+#    #+#             */
/*   Updated: 2025/10/27 19:20:02 by mmubina          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*_fill_line_buffer(int fd, char *left_c, char *buffer);
static char	*_set_line(char *line);
char		*ft_strchr(char *s, int c);
static char	*extract_line(char *remainder);

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
	line = extract_line(remainder);
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

	newline_found = ft_strchr(remainder, '\n');
	bytes_read = read(fd, buffer, BUFFER_SIZE);
	while (!newline_found && bytes_read > 0)
	{
		buffer[bytes_read] = '\0';
		if (remainder == NULL)
			remainder = ft_strdup(buffer);
		else
			remainder = ft_strjoin(remainder, buffer);
		if (!remainder)
			return (NULL);
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
	char	*new_remainder;

	i = 0;
	while (line_buffer[i] != '\0' && line_buffer[i] != '\n')
		i++;
	if (line_buffer[i] == '\n')
		i++;
	if (line_buffer[i] == '\0')
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
	int		j;
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
	j = 0;
	while (j < i)
	{
		line[j] = remainder[j];
		j++;
	}
	line[j] = '\0';
	return (line);
}

// int	main(void)
// {
// 	int		fd;
// 	char	*line;

// 	fd = open("test.txt", O_RDONLY);
// 	line = get_next_line(fd);
// 	while (*line != '\n')
// 	{
// 		printf("%s", line);
// 	}
// 	close(fd);
// 	return (0);
// }
