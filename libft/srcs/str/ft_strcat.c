#include <string.h>
#include "libft.h"

char	*ft_strcat(char *s1, const char *s2)
{
	size_t	i;
	size_t	len;

	i = 0;
	len = ft_strlen(s1);
	while (s1 && s2 && s2[i])
	{
		s1[len + i] = s2[i];
		i++;
	}
	s1 ? s1[len + i] = '\0' : 0;
	return (s1);
}
