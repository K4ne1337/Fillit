#ifndef _FT_SOLVE_H_
#define _FT_SOLVE_H_

#include <stdio.h>

#include "tetrimino.h"
#include "../libft/libft.h"

int		checkFreePos(Tetrimino *tetrimino, char **grid, int pos, int size);
char	**createGrid(int size);
void	solve(TetriminoList *tetri_list);
void	displayGrid(char **grid);
void	placeBlockOnGrid(Tetrimino *tetrimino, int position, char **grid, int index, int size);


#endif