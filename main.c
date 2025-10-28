
#include "get_next_line.h"

int	main(void)
{
	int		fd;
	int		fd1;
	char	*line;

	fd = open("test.txt", O_RDONLY);
	fd1 = open("test1.txt", O_RDONLY);
	if (fd < 0 || fd1 < 0)
		return (1);
	*line = get_next_line_bonus(fd, fd1);
	while (line != NULL)
	{
		printf("%s", line);
		free(line);
		*line = get_next_line_bonus(fd, fd1);
	}
	close(fd);
	close(fd1);
	return (0);
}
