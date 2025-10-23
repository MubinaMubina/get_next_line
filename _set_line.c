/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   _set_line.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmubina <mmubina@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/22 10:54:00 by mmubina           #+#    #+#             */
/*   Updated: 2025/10/23 18:43:02 by mmubina          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*_set_line(char *line_buffer)
{
	int			i;
	static char	*remainder;

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
