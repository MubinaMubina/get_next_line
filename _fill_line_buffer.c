/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   _fill_line_buffer.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmubina <mmubina@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/22 10:47:31 by mmubina           #+#    #+#             */
/*   Updated: 2025/10/22 15:04:45 by mmubina          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*_fill_line_buffer(int fd, char *remainder, char *buffer)
{
	char *line_buffer;
	int i;
	static char *remainder;
	ssize_t bytes_read;

	i = 0;
	
	while (bytes_read = read(fd, buffer, strlen(buffer)) > 0)
	{
		if (remainder[i] == NULL)
			ft_strdup(remainder);
		else
			remainder = ft_strjoin(remainder, buffer);
		if (buffer[i] == '\n')
			break;
		i++;	
	}
	return (remainder);
}