#include "fillit.h"

int	main(int argc, char **argv)
{
	char	**str_tetri;
	TetriminoList tetri_list;
	
	str_tetri = NULL;
	tetri_list.list = NULL;
	tetri_list.size = 0;

	if(argc != 2)
	{
		ft_putendl("usage: missing arg");
		return(1);
	}
	str_tetri = (char **)malloc(sizeof(char *) * 26);
	if (read_file(argv[1], str_tetri, &tetri_list.size) == -1)
	{
		ft_putendl("error");
		exit(1);
	}
	tetri_list.list = (Tetrimino *)malloc(sizeof(Tetrimino) * tetri_list.size);
	fillList(&tetri_list, str_tetri);
	solve(&tetri_list);
	//printf("%d\n", tetri_counter);
	//for(int i = 0; i < tetri_counter; ++i)
		//printf("\n%s", str_tetri[i]);

	return (0);
}