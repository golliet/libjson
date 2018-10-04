#include <stdlib.h>
#include "libft.h"

char		*dupspec(const char *s1)
{
	char	*dest;
	int		i;
	int		j;

	i = 0;
	j = 0;
	if (!(dest = (char *)malloc(sizeof(char) * 2 * (ft_strlen(s1) + 1))))
		return (NULL);
	while (s1[i])
	{
		if ((s1[i] == '`' || s1[i] == '$' || s1[i] == '?' || s1[i] == '*'
		|| s1[i] == ' ') && (!i || !nbcks(s1, i - 1)))
			dest[j++] = '\\';
		dest[j++] = s1[i++];
	}
	dest[j] = '\0';
	return (dest);
}
