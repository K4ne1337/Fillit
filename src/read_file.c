/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelkhay <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/18 15:38:45 by abelkhay          #+#    #+#             */
/*   Updated: 2019/03/18 15:38:47 by abelkhay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "read_file.h"

int		read_file(char *filename, char **str_tetri, int *tetri_counter)
{
	int		fd;
	int		ret;
	char	buffer[22];
	int temp;

	fd = open(filename, O_RDONLY);
	if(fd == -1)
		return (-1);
	while((ret = read(fd, buffer, 21)))
	{
		if(ret != 21 && ret != 20)
			return (-1);
		buffer[ret] = '\0';
		str_tetri[*tetri_counter] = ft_strdup(buffer);
		if(!str_tetri)
			return (-1);
		if(verify_block(str_tetri[*tetri_counter]) == -1)
			return (-1);
		(*tetri_counter)++;
		if(*tetri_counter > 26)
			return (-1);
		temp = ret;
	}
	if (temp != 20)
		return (-1);
	return (0);
}
