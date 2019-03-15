#include <strings.h>
#include "libft.h"

void	ft_bzero (void *s, size_t n)
{
	size_t	i;
	char	*s2;

	i = 0;
	s2 = s;
	while (i < n)
	{
		s2[i] = '\0';
		i++;
	}
}
