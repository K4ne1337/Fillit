#ifndef _TETRIMINO_HEADER_H_
#define _TETRIMINO_HEADER_H_

#include <stdio.h>

#include "verify_block.h"
#include "../libft/libft.h"

typedef struct 	Tetrimino
{
	char	block[4][4];
	char	id;
}				Tetrimino;

typedef struct 	TetriminoList
{
	Tetrimino *list;
	int size;
}				TetriminoList;

void	addBlock(char *src, Tetrimino *dest);
void	fillList(TetriminoList *tetri_list, char **str_tetri);
void	blockUp(Tetrimino *tetri);
void	blockLeft(Tetrimino *tetri);

#endif