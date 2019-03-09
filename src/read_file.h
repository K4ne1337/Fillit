#ifndef _READ_FILE_H_
#define _READ_FILE_H_

#include <stdlib.h>
#include <fcntl.h>
#include <stdio.h>

#include "verify_block.h"
#include "../libft/libft.h"

int		read_file(char *filename, char **str_tetri, int *tetri_counter);

#endif