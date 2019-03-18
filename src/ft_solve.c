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

#include "ft_solve.h"

int	checkIfBlockFits(Tetrimino *tetrimino, char **grid, int pos, int size)
{
	int x;
	int y;
	int i;
	int j;

	x = pos % size;
	y = pos / size;
	i = 0;
	while(i < 4)
	{
		j = 0;
		while(j < 4)
		{
			if(tetrimino->block[j][i] == '#')
			{
				if(x + j >= size || y + i >= size)
					return 1;
				else if(grid[x + j][y + i] != '.')
					return 1;
			}
			++j;
		}
		++i;
	}
	return (0);
}

int	findFreePos(TetriminoList *tetri_list, int index, char **grid, int size)
{
	int i;
	int j;

	i = 0;
	while(i < size)
	{
		j = 0;
		while(j < size)
		{
			if(checkIfBlockFits(&tetri_list->list[index],grid, (i * size + j), size) == 0)
			{
				placeBlockOnGrid(&tetri_list->list[index], i * size + j, grid, size, 0);
				if(index + 1 == tetri_list->size)
					return (0);
				if(findFreePos(tetri_list, index + 1, grid, size) == -1)
					placeBlockOnGrid(&tetri_list->list[index], i * size + j, grid, size, 1);
				else
					return (0);
			}
			++j;
		}
		++i;
	}
	return (-1);
}


void	placeBlockOnGrid(Tetrimino *tetrimino, int position, char **grid, int size, int mode)
{
	int 	x;
	int 	y;
	int 	i;
	int 	j;
	char	c;

	x = position % size;
	y = position / size;
	i = 0;
	j = 0;
	if (mode == 0)
		c = tetrimino->id;
	else
		c = '.';
	while(j < 4)
	{
		while(i < 4)
		{
			if (tetrimino->block[i][j] == '#')
				grid[x + i][y + j] = c;
			++i;
		}
		++j;
		i = 0;
	}
}

char	**createGrid(int size)
{
	int		i;
	int		j;
	char	**ret;

	i = 0;
	ret = (char **)malloc(sizeof(char *) * size + 1);
	while(i < size)
	{
		ret[i] = (char *)malloc(sizeof(char) * size);
		j = 0;
		while(j < size)
		{
			ret[i][j] = '.';
			++j;
		}
		ret[i][j] = '\0';
		++i;
	}
	return (ret);
}

void	displayGrid(char **grid, int size)
{
	int x;
	int	y;
	
	x = 0;
	y = 0;

	while(y < size)
	{
		x = 0;
		while(x < size)
		{
			ft_putchar(grid[x][y]);
			++x;
		}
		ft_putchar('\n');
		++y;
	}
}

void	solve(TetriminoList *tetri_list)
{
	int		size;
	char	**grid;
	int		sqr;

	sqr = 0;
	while(sqr *  sqr < (tetri_list->size * 4))
			sqr++;
	size = sqr;
	grid = createGrid(size);
	while(findFreePos(tetri_list, 0, grid, size) == -1)
	{
		free(grid);
		size++;
		grid = createGrid(size);
	}
	displayGrid(grid, size);
	free(grid);
}
