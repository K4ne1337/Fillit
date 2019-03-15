#include "libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	char	*fresh;
	size_t	i;

	if (!s)
		return (NULL);
	fresh = (char *)malloc(sizeof(char) * ft_strlen(s) + 1);
	if (fresh == NULL)
		return (NULL);
	i = 0;
	while (s[i])
	{
		fresh[i] = (*f)(s[i]);
		i++;
	}
	fresh[i] = '\0';
	return (fresh);
}
