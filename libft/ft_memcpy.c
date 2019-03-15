/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memcpy.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelkhay <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/12 12:38:40 by abelkhay          #+#    #+#             */
/*   Updated: 2018/11/12 15:18:16 by abelkhay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t i;
	char	*a;
	char	*b;

	i = 0;
	a = (char *)dst;
	b = (char *)src;
	while (i < n)
	{
		a[i] = b[i];
		i++;
	}
	return (dst);
}
