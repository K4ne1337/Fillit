/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_solve.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelkhay <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/18 15:38:37 by abelkhay          #+#    #+#             */
/*   Updated: 2019/03/18 16:58:39 by amarcel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#	ifndef BLOCK_H
#	define BLOCK_H

#include "tetrimino.h"

void	placeblock(t_tetrimino *tetrimino, int position, char **grid, int size);
void	removeblock(t_tetrimino *tetrimino, int position, char **grid, int size);
int		checkblock(t_tetrimino *tetrimino, char **grid, int pos, int size);

#	endif
