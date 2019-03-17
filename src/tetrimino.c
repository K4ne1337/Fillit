#include "tetrimino.h"


void	addBlock(char *src, Tetrimino *dest)
{
	int	i;
	int	x;
	int	y;

	i = 0;
	x = 0;
	y = 0;
	while(i < 19)
	{
		if(src[i] != '\n')
		{ 
			dest->block[x][y] = src[i];
			x++;
		}
		else
		{
			y++;
			x = 0;
		}
		i++;
	}
}

void	fillList(TetriminoList *tetri_list, char **str_tetri)
{
	int	i;
	char id;

	id = 'A';
	i = 0;
	while(i < tetri_list->size)
	{
		addBlock(str_tetri[i], &tetri_list->list[i]);
		tetri_list->list[i].id = id;
		blockLeft(&tetri_list->list[i]);
		blockUp(&tetri_list->list[i]);
		++i;
		id++;
	}
}

void	blockLeft(Tetrimino *tetri)
{ 
	int y;
	int n;
	int	x;

	y = 0;
	x = 0;
	while(x < 4)
	{  
		if(tetri->block[x][y] != '#' && tetri->block[x][y+1] != '#' && tetri->block[x][y+2] != '#' && 
		tetri->block[x][y+3] != '#')
		{
			n = x + 1;
			while (y < 4 && n < 4)
			{
				ft_swap(&tetri->block[x][y], &tetri->block[n][y]);
				y++;
			}
		}
		x++;
		y = 0;
	}
	if(tetri->block[0][y] != '#' && tetri->block[0][y+1] != '#' && tetri->block[0][y+2] != '#' && 
		tetri->block[0][y+3] != '#')
		blockLeft(tetri);
}

void	blockUp(Tetrimino *tetri)
{ 
	int y;
	int n;
	int	x;

	y = 0;
	x = 0;
	while(y < 4)
	{  
		if(tetri->block[x][y] != '#' && tetri->block[x+1][y] != '#' && tetri->block[x+2][y] != '#' && 
		tetri->block[x+3][y] != '#')
		{
			n = y + 1;
			while (x < 4 && n < 4)
			{
				ft_swap(&tetri->block[x][y], &tetri->block[x][n]);
				x++;
			}
		}
		y++;
		x = 0;
	}
	if(tetri->block[x][0] != '#' && tetri->block[x+1][0] != '#' && tetri->block[x+2][0] != '#' && 
		tetri->block[x+3][0] != '#')
		blockUp(tetri);
}