#include "libft.h"

char	*ft_strlcpy(char *dst, const char *src, int *len)
{
	size_t i;
	size_t k;

	k = 0;
	i = ft_strlen(src);
	while (k < i)
	{
		dst[k] = src[k];
		k++;
	}
	dst[k] = '\0';
	(*len) += (int)k;
	return (dst);
}
