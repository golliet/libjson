
#include "json.h"

void		wy_exit(char *str)
{
	ft_putendl_fd(str, 2);
	exit(EXIT_FAILURE);
}

void		wy_is_end(char c)
{
	if (c != '\0')
		return ;
	wy_exit("\0");
}

void        wy_level(int level)
{
	int i;

	i = 0;
	while (i < level)
	{
		ft_putstr("|");
		i++;
	}
}

int			wy_is_space(char c)
{
	return (c == '\t' || c == '\n' || c == '\r' || c == ' ');
}