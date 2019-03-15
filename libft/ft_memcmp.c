#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t i;
	unsigned char *a;
	unsigned char *b;

	i = 0;
	if (n == 0)
		return (0);
	a = (unsigned char *)s1;
	b = (unsigned char *)s2;
	while(a[i] == b[i] && i < n)
	{
		if (i == (n - 1))
			return (0);
		i++;
	}
	return (a[i] - b[i]);
}
