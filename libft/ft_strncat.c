#include "libft.h"

char	*ft_strncat(char *dest, const char *src, size_t n)
{
	size_t i;
	size_t y;

	i = 0;
	y = 0;
	while (dest[i] != '\0')
	{
		i++;
	}
	while (src[y] != '\0' && y < n)
	{
		dest[i] = src[y];
		i++;
		y++;
	}
	dest[i] = '\0';
	return (dest);
}
