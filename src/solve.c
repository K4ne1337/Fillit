#include "solve.h"

void	solve(TetriminoList *tetri_list)
{
	int i;
	int j;
	int currentBlockPlacement[26];
	Solution currentSolution;
	currentSolution.size = 0;
	currentSolution.XYSum = 0;

	i = 0;
	while(i < 26)
	{
		currentBlockPlacement[i] = -1;
		++i;
	}

	solveBlock(tetri_list, 0, 0, currentBlockPlacement, &currentSolution);

	displayGrid(tetri_list, currentBlockPlacement, 10);
}

void	solveBlock(TetriminoList *tetri_list, int blockIndex, int position, int currentBlockPlacement[26], Solution *currentSolution)
{
	if(position == 0)
	{
		currentBlockPlacement[blockIndex] = 0;
	}
}

void	placeBlockOnGrid(Tetrimino *tetrimino, int position, char grid[104][104])
{
	int x;
	int y;
	int i;
	int j;
	x = position % 104;
	y = position / 104;
	i = 0;
	j = 0;

	while(i < 4)
	{
		while(j < 4)
		{
			if(tetrimino->block[i][j] == '#')
				grid[x + i][y + j] = tetrimino->id;
			++j;
		}
		++i;
		j = 0;
	}
}

int		checkIfBlockFits(TetriminoList *tetri_list, int blockIndex, int position, int currentBlockPlacement[26])
{
	int x;
	int y;
	int i;
	int j;
	x = position % 104;
	y = position / 104;
	i = 0;
	j = 0;

	while(i < 4)
	{
		while(j < 4)
		{
			if(tetri_list->list[blockIndex].block[i][j] == '#' && checkFreePosition(tetri_list, currentBlockPlacement, ((y + j) * 104) + (x + i)))
				return 0;
			++j;
		}
		++i;
		j = 0;
	}
	return 1;
}

int		checkFreePosition(TetriminoList *tetri_list, int currentBlockPlacement[26], int position)
{

}

void	displayGrid(TetriminoList *tetri_list, int currentBlockPlacement[26], int size)
{
	char grid[104][104];
	int i = 0;
	int j = 0;
	int n = 0;
	int y = 0;

	i = 0;
	j = 0;
	while(i < 104)
	{
		while(j < 104)
		{
			grid[i][j] = '.';
			++j;
		}
		j = 0;
		++i;
	}

	i = 0;
	while(i < 26)
	{
		if(currentBlockPlacement[i] != -1)
			placeBlockOnGrid(&tetri_list->list[i], currentBlockPlacement[i], grid);
		++i;
	}

	while(y < size)
	{
		while(n < size)
		{
			ft_putchar(grid[n][y]);
			n++;
		}
		ft_putendl("");
		n = 0;
		y++;
	}
	ft_putendl("");
}