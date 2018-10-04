#ifndef __GET_NEXT_LINE_H
# define __GET_NEXT_LINE_H
# include "libft.h"
# include <sys/types.h>
# include <sys/uio.h>
# include <stdlib.h>
# include <unistd.h>
# define BUFF_SIZE 1000

int					get_next_line(const int fd, char **line);
#endif
