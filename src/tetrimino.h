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

int		xShift(Tetrimino *dest);
int		LenShape(Tetrimino *dest);
void 	cpyBlock(Tetrimino *dest, char tempo[4][4]);
void	addBlock(char *src, Tetrimino *dest);
void	fillList(TetriminoList *tetri_list, char **str_tetri);
void	blockUp(char block[4][4]);
void	blockLeft(char block[4][4]);
void	displayTetrimino(Tetrimino *dest);
void	blockReplaceC(char block[4][4]);
void	blockReplaceL(char block[4][4]);
void	returnBlock(char block[4][4], Tetrimino *dest);

#endif