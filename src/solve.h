#ifndef _SOLVE_H_
#define _SOLVE_H_

#include <stdio.h>

#include "tetrimino.h"
#include "../libft/libft.h"

typedef struct 	Solution
{
	int blockPlacement[26];
	int size;
	int XYSum;
}				Solution;

void	solve(TetriminoList *tetri_list);
void	solveBlock(TetriminoList *tetri_list, int blockIndex, int position, int currentBlockPlacement[26], Solution *currentSolution);
void	placeBlockOnGrid(Tetrimino *tetrimino, int position, char grid[104][104]);
int		checkIfBlockFits(TetriminoList *tetri_list, int blockIndex, int position, int currentBlockPlacement[26]);
int		checkFreePosition(TetriminoList *tetri_list, int currentBlockPlacement[26], int position);
void	displayGrid(TetriminoList *tetri_list, int currentBlockPlacement[26], int size);

#endif