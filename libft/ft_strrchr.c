#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	*str;
	size_t	len;

	len = ft_strlen(s);
	str = (char *)s;
	if (c == '\0')
		return ((char *)s + len);
	str = (str + len) - 1;
	while (len > 0)
	{
		if (*str == c)
			return (str);
		str--;
		len--;
	}
	return (NULL);
}
