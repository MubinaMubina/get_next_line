

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

# include <fcntl.h>
# include <limits.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}					t_list;

char				*ft_substr(char const *s, unsigned int start, size_t len);
ssize_t				ft_strlen(const char *s);
char				*ft_strjoin(char *s1, char const *s2);
char				*ft_strdup(const char *src);
char				*get_next_line(int fd);
char				*ft_strchr(const char *s, int c);

#endif
