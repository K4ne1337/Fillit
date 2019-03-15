#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	size_t i;
	char *fresh;

	i = 0;
	if (!s)
		return (NULL);
	fresh = (char *)malloc(sizeof (char) * len + 1);
	if (!fresh)
		return (NULL);
	while (s[start] != '\0' && len-- > 0)
	{
		fresh[i] = s[start];
		i++;
		start++;
	}
	fresh[i] = '\0';
	return (fresh);
}
