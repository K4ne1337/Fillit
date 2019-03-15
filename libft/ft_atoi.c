#include "libft.h"

int	ft_atoi(const char *nptr)
{
	int i;
	int neg;
	int nb;

	i = 0;
	neg = 1;
	nb = 0;
	while(nptr[i] == ' ' || (nptr[i] >= 9 && nptr[i] <= 13))
		i++;
	if (nptr[i] == '+' || nptr[i] == '-')
	{
		if(nptr[i] == '-')
			neg = -1;
		i++;
	}
	while (nptr[i] >= '0' && nptr[i] <= '9')
	{
		nb = nb * 10;
		nb = (nptr[i] - '0') + nb;
		i++;
	}
	return (neg * nb);
}
