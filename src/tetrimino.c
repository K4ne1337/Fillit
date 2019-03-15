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

void	eraseBlock(Tetrimino *dest)
{
	int	i;
	int	j;

	j = 0;
	while(i < 4)
	{
		while(j < 4)
		{
			if(dest->block[i][j] == '#')
				dest->block[i][j] = '.';
			j++;
		}
		i++;
		j = 0;
	}
}
void cpyBlock(Tetrimino *dest, char tempo[4][4])
{ 
	int	i;
	int	j;

	i = 0;
	j = 0;
	while(i < 4)
	{
		while(j < 4)
		{
			tempo[j][i] = dest->block[j][i];
			j++;
		}
		j = 0;
		++i;
	}
}

void	fillList(TetriminoList *tetri_list, char **str_tetri)
{
	int	i;
	char id;
	char	tempo[4][4];

	id = 'A';
	i = 0;
	while(i < tetri_list->size)
	{
		addBlock(str_tetri[i], &tetri_list->list[i]);
		tetri_list->list[i].id = id;
		cpyBlock(&tetri_list->list[i], tempo);
		blockLeft(tempo);
		blockUp(tempo);
		returnBlock(tempo, &tetri_list->list[i]);
		++i;
		id++;
	}
}

void	blockLeft(char block[4][4])
{ 
	int y;
	int n;
	int	x;

	y = 0;
	x = 0;
	while(x < 4)
	{  
		if(block[x][y] != '#' && block[x][y+1] != '#' && block[x][y+2] != '#' && 
		block[x][y+3] != '#')
		{
			n = x + 1;
			while (y < 4 && n < 4)
			{
				ft_swap(&block[x][y], &block[n][y]);
				y++;
			}
		}
		x++;
		y = 0;
	}
	if(block[0][y] != '#' && block[0][y+1] != '#' && block[0][y+2] != '#' && 
		block[0][y+3] != '#')
		blockLeft(block);
}

void	blockReplaceC(char block[4][4])
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	while(y < 4)
	{
		if(block[x][y] != '#' && block[x+1][y] != '#' && block[x+2][y] != '#' && 
		block[x+3][y] != '#')
		{
			while(x < 4)
			{
				block[x][y] = 'o';
				x++;
			}
		}
		x = 0;
		y++;
	}
}

void	blockUp(char block[4][4])
{ 
	int y;
	int n;
	int	x;

	y = 0;
	x = 0;
	while(y < 4)
	{  
		if(block[x][y] != '#' && block[x+1][y] != '#' && block[x+2][y] != '#' && 
		block[x+3][y] != '#')
		{
			n = y + 1;
			while (x < 4 && n < 4)
			{
				ft_swap(&block[x][y], &block[x][n]);
				x++;
			}
		}
		y++;
		x = 0;
	}
	if(block[x][0] != '#' && block[x+1][0] != '#' && block[x+2][0] != '#' && 
		block[x+3][0] != '#')
		blockUp(block);
}

void	blockReplaceL(char block[4][4])
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	while(x < 4)
	{
		if(block[x][y] != '#' && block[x][y+1] != '#' && block[x][y+2] != '#' && 
		block[x][y+3] != '#')
		{
			while(y < 4)
			{
				block[x][y] = 'o';
				y++;
			}
		}
		y = 0;
		x++;
	}
}

void	returnBlock(char block[4][4], Tetrimino *dest)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	while(x < 4)
	{
		while(y < 4)
		{
			dest->block[y][x] = block[y][x];
			y++;
		}
		y = 0;
		x++;
	}
}

void	displayTetrimino(Tetrimino *dest)
{
	int x = 0;
	int y = 0;
	while(y < 4)
	{
		while(x < 4)
		{
			if(dest->block[x][y] == '#')
				ft_putchar(dest->id);
			else
			{
				ft_putchar(dest->block[x][y]);
			}
			x++;
		}
		ft_putendl("");
		x = 0;
		y++;
	}
	ft_putendl("");
}