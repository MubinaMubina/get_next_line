/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   _fill_line_buffer.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmubina <mmubina@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/22 10:47:31 by mmubina           #+#    #+#             */
/*   Updated: 2025/10/23 20:11:02 by mmubina          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

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
