/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelkhay <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/18 15:37:58 by abelkhay          #+#    #+#             */
/*   Updated: 2019/03/18 19:15:58 by abelkhay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	ft_error(void)
{
	ft_putendl("error");
	exit(1);
}

int		main(int argc, char **argv)
{
	char			**str_tetri;
	t_tetriminolist	tetri_list;

	str_tetri = NULL;
	tetri_list.list = NULL;
	tetri_list.size = 0;
	if (argc != 2)
	{
		ft_putendl("usage: ./fillit source_file\n");
		return (1);
	}
	if (!(str_tetri = (char **)malloc(sizeof(char *) * 26)))
		ft_error();
	if (read_file(argv[1], str_tetri, &tetri_list.size) == -1)
		ft_error();
	if (!(tetri_list.list = (t_tetrimino *)\
					malloc(sizeof(t_tetrimino) * tetri_list.size)))
		ft_error();
	ft_filllist(&tetri_list, str_tetri);
	solve(&tetri_list);
	freegrid(str_tetri);
	free(tetri_list.list);
	return (0);
}
