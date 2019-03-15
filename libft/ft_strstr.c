#include "libft.h"

char	*ft_strstr(const char *haystack, const char *needle)
{
	size_t i;
	size_t n;

	i = 0;
	if(*needle == '\0')
		return ((char *)haystack);
	while (haystack[i])
	{
		n = 0;
		while (haystack[i + n] == needle[n])
		{
			n++;
			if (needle[n] == '\0')
				return ((char *)haystack + i);
		}
		i++;
	}
	return (NULL);
}
