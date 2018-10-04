#include "libft.h"

void	ft_strdel(char **as)
{
	if (!as)
		return ;
	if (!(*as))
		return ;
	ft_strclr(*as);
	free(*as);
	*as = NULL;
	as = NULL;
}
