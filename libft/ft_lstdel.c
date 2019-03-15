#include "libft.h"

void	ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	t_list *suppr;

	suppr = *alst;
	while(suppr)
	{
		*alst = suppr->next;
		ft_lstdelone(&suppr, del);
		suppr = *alst;
	}
}
