/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_solve.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelkhay <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/18 15:38:37 by abelkhay          #+#    #+#             */
/*   Updated: 2019/03/18 17:01:19 by amarcel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#	ifndef SOLVE_H
#	define SOLVE_H

#include "tetrimino.h"
#include "../libft/libft.h"
#include "block.h"

int		findfreepos(t_tetriminolist *tetri_list, int index,\
		char **grid, int size);
int		checkfreepos(t_tetrimino *tetrimino, char **grid, int pos, int size);
char	**creategrid(int size);
void	solve(t_tetriminolist *tetri_list);
void	displaygrid(char **grid, int size);

#	endif
