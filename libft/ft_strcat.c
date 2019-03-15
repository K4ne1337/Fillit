#include "libft.h"

char	*ft_strcat(char *dest, const char *src)
{
	int i;
	int y;

	i = 0;
	y = 0;
	while(dest[i] != '\0')
		i++;
	while(src[y] != '\0')
	{
		dest[i] = src[y];
		i++;
		y++;
	}
	dest[i] = '\0';
	return (dest);
}
