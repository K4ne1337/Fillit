/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verify_block.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelkhay <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/18 15:39:13 by abelkhay          #+#    #+#             */
/*   Updated: 2019/03/18 15:39:15 by abelkhay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "verify_block.h"

int	verify_block(char buf[22])
{
	int	i;
	int	countdot;
	int	countdiez;
	int	countend;

	i = 0;
	countdot = 0;
	countdiez = 0;
	countend = 0;
	while (buf[i])
	{
		if ((buf[i] == '#') && (countdiez == 3 || buf[i + 1] == '#' || buf[i + 3] == '#' || buf[i + 4] == '#' || buf[i + 5] == '#'))
			countdiez++;
		if (buf[i] == '.')
			countdot++;
		if (buf[i] == '\n')
			countend++;
		i++;
	}
	if (countdot == 12 && countdiez == 4 && (countend == 5 || countend == 4))
		return (0);
	return (-1);
}
