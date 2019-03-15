#include "libft.h"

char	*ft_strnew(size_t size)
{
	char *memo;

	memo = (char *)malloc(sizeof(char) * size + 1);
	if (!memo)
		return (NULL);
	ft_bzero(memo, size + 1);
	return (memo);
}
