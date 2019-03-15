#include "libft.h"

static char	*ft_cpyitoa(char *str, long int len, long int nb, int neg)
{
	int i;

	i = 0;
	if (neg == 1)
	{
		str[i] = '-';
		i++;
	}
	while (len >= 1)
	{
		str[i] = (nb / len) + '0';
		nb = nb % len;
		len = len / 10;
		i++;
	}
	str[i] = '\0';
	return (str);
}

char	*ft_itoa(int n)
{
	int			i;
	long int	nb;
	char		*str;
	int			neg;
	long int	len;

	i = 0;
	nb = n;
	neg = 0;
	len = 1;
	if (nb < 0)
	{
		neg = 1;
		nb = nb * -1;
	}
	while (nb / len >= 10)
	{
			i++;
		len = len * 10;
	}
	str = (char *)malloc(sizeof(char) * i + neg + 2);
	if (!str)
		return (NULL);
	str = ft_cpyitoa(str, len, nb, neg);
	return (str);
}
