
#include "get_next_line.h"

char	*read_file_once(int fd, size_t buffer_size)
{
	char		*buffer;
	ssize_t		bytes_read;
	int			i;
	static char	*remainder;
	int			len;
	int			j;

	buffer = malloc((buffer_size + 1) * sizeof(char));
	if (!buffer)
		return (NULL);
	while ((bytes_read = read(fd, buffer, buffer_size)) > 0)
	{
		i = 0;
		while (i < bytes_read && buffer[i] != '\n')
		{
			write(1, &buffer[i], 1);
			i++;
		}
		if (buffer[i] == '\n')
		{
			write(1, "\n", 1);
			i++;
		}
	}
	if (buffer[i] == '\n')
	{
		len = bytes_read - (i + 1);
		remainder = malloc((len + 1) * sizeof(char));
		if (!remainder)
			return (NULL);
	}
	j = 0;
	while (j < len)
	{
		remainder[j] = buffer[i + j + 1];
		j++;
	}
	remainder[len] = '\0';
	buffer[i + 1] = '\0';
	return (buffer);
}
