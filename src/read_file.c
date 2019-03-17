#include "read_file.h"

int		read_file(char *filename, char **str_tetri, int *tetri_counter)
{
	int		fd;
	int		ret;
	char	buffer[22];

	fd = open(filename, O_RDONLY);
	if(fd == -1)
		return (-1);
	while((ret = read(fd, buffer, 21)))
	{
		if(ret != 21 && ret != 20)
			return (-1);
		buffer[19] = '\0';
		str_tetri[*tetri_counter] = (char *)malloc(sizeof(char) * 20);
		if(!str_tetri)
			return (-1);
		ft_strcpy(str_tetri[*tetri_counter], buffer);
		str_tetri[*tetri_counter][19] = '\n';
		str_tetri[*tetri_counter][20] = '\0';
		if(verify_block(str_tetri[*tetri_counter]) == -1)
			return (-1);
		(*tetri_counter)++;
		if(*tetri_counter > 26)
			return (-1);
	}
	return (ret);
}