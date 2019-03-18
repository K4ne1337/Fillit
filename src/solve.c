/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_solve.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelkhay <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/18 15:38:30 by abelkhay          #+#    #+#             */
/*   Updated: 2019/03/18 15:38:32 by abelkhay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "solve.h"

int		findfreepos(t_tetriminolist *tetri_list, int index, char **grid, int size)
{
	int i;
	int j;

	i = -1;
	while (++i < size)
	{
		j = -1;
		while (++j < size)
		{
			if (checkblock(&tetri_list->list[index], grid,\
			(i * size + j), size) == 0)
			{
				placeblock(&tetri_list->list[index],\
				i * size + j, grid, size);
				if (index + 1 == tetri_list->size)
					return (0);
				if (findfreepos(tetri_list, index + 1, grid, size) == -1)
					removeblock(&tetri_list->list[index],\
					i * size + j, grid, size);
				else
					return (0);
			}
		}
	}
	return (-1);
}

char	**creategrid(int size)
{
	int		i;
	int		j;
	char	**ret;

	i = 0;
	ret = (char **)malloc(sizeof(char *) * size + 1);
	while (i < size)
	{
		ret[i] = (char *)malloc(sizeof(char) * size);
		j = 0;
		while (j < size)
		{
			ret[i][j] = '.';
			++j;
		}
		ret[i][j] = '\0';
		++i;
	}
	return (ret);
}

void	displaygrid(char **grid, int size)
{
	int x;
	int	y;

	x = 0;
	y = 0;
	while (y < size)
	{
		x = 0;
		while (x < size)
		{
			ft_putchar(grid[x][y]);
			++x;
		}
		ft_putchar('\n');
		++y;
	}
}

void	solve(t_tetriminolist *tetri_list)
{
	int		size;
	char	**grid;
	int		sqr;

	sqr = 0;
	while (sqr * sqr < (tetri_list->size * 4))
		sqr++;
	size = sqr;
	grid = creategrid(size);
	while (findfreepos(tetri_list, 0, grid, size) == -1)
	{
		free(grid);
		size++;
		grid = creategrid(size);
	}
	displaygrid(grid, size);
	free(grid);
}
