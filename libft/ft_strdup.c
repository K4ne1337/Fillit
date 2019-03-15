#include "libft.h"
#include <stdlib.h>

char	*ft_strdup(const char *s)
{
	int len;
	int i;
	char *dest;
	
	len = 0;
	i = 0;
	while (s[len])
	{
		len++;
	}
	dest = (char *)malloc(sizeof(char) * len + 1);
	while (s[i])
	{
		dest[i] = s[i];
		i++;
	}
	dest[i] = '\0';
	return(dest);
}
