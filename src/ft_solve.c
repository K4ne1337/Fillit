#include "ft_solve.h"

int	checkFreePos(char **grid, int position, int size)
{
	int x;
	int y;
	int i;
	int j;

	x = position / size;
	y = position % size;
	i = 0;
	j = 0;
	while(i < 4)
	{
		j = 0;
		while(j < 4)
		{
			if(grid[x][y] != '.')
			//if(grid[x + i][y + j] >= 'A' && grid[x + i][y + j] <= 'Z')
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}


void	placeBlockOnGrid(Tetrimino *tetrimino, int position, char **grid, int index, int size)
{
	int x;
	int y;
	int i;
	int j;

	x = position / size;
	y = position % size;
	i = 0;
	j = 0;
	while(i < 4)
	{
		while(j < 4)
		{
			if (tetrimino->block[i][j] == '#')
				grid[x + i][y + j] = tetrimino->id;
			++j;
		}
		++i;
		j = 0;
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
			j++;
		}
		ret[i][j] = '\0';
		i++;
	}
	return (ret);
}

void	displayGrid(char **grid)
{
	int x;
	int	y;
	
	x = 0;
	y = 0;
	while(grid[x])
	{
		y = 0;
		while (grid[x][y])
		{
			ft_putchar(grid[x][y]);
			y++;
		}
		ft_putchar('\n');
		x++;
	}
}

void	solve(TetriminoList *tetri_list)
{
	int		size;
	int		i;
	int		pos;
	char	**grid;

	size = 10;
	i = 0;
	pos = 0;
	grid = createGrid(size);
	while(i < tetri_list->size)
	{
		if(checkFreePos(grid, pos, size) == 0)
		{
			placeBlockOnGrid(&tetri_list->list[i], pos, grid, i, size);
			//placeBlockOnGrid(&tetri_list->list[i+1], pos+1, grid, i, size);
			i++;
		}
		else
			pos++;
	}
		displayGrid(grid);
}