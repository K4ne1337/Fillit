#include "libft.h"

void	*ft_memalloc(size_t size)
{
	char *memo;

	if ((memo = (char *)malloc(sizeof(char) * size)) == 0)
		return (NULL);
	ft_bzero((void *)memo, size);
	return ((void *)memo);
}
