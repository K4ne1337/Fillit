#include "libft.h"

static int	ft_count_words(const char *s, char c)
{
	int i;
	int y;

	i = 0;
	y = 0;
	while (s[y] != '\0')
	{
		while (s[y] != '\0' && s[y] == c)
			y++;
		if (s[y] != '\0')
			i++;
		while (s[y] != '\0' && s[y] != c)
			y++;
	}
	return (i);
}

static char	**ft_strdup_split(char const *str, int i, char **tab, char c)
{
	int j;
	int nb_char;

	j = 0;
	nb_char = 0;
	while (!(str[j] == c) && str[j] != '\0')
	{
		nb_char++;
		j++ ;
	}
	tab[i] = (char *)malloc(sizeof(char) * nb_char + 1);
	if (tab == NULL)
		return (NULL);
	j = 0;
	while (!(str[j] == c) && str[j] != '\0')
	{
		tab[i][j] = str[j];
		j++;
	}
	tab[i][j] = '\0';
	return (tab);
}

char	**ft_strsplit(char const *s, char c)
{
	size_t i;
	size_t y;
	char **tab;

	i = 0;
	if (s == NULL)
		return (NULL);
	y = ft_count_words(s, c);
	tab = (char **)malloc(sizeof(char *) * (y + 1));
	if (tab == NULL)
		return (NULL);
	while (i < y)
	{
		while (*s == c)
			s++;
		ft_strdup_split(s, i, tab, c);
		while (!(*s == c) && *s != '\0')
			s++;
		i++;
	}
	tab[i] = 0;
	return (tab);
}
