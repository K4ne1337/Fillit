#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*fresh;

	if (!s1 || !s2)
		return (NULL);
	fresh = (char *)malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2)) + 1);
	if (!fresh)
		return (NULL);
	ft_strcpy(fresh, s1);
	ft_strcat(fresh, s2);
	return (fresh);
}
