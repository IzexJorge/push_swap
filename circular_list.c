
#include "push_swap.h"

t_clist	*ft_clstnew(void *content)
{
	t_clist	*p;

	p = malloc(sizeof(t_clist));
	if (p == NULL)
		return (0);
	p->content = content;
    p->prev = NULL;
	p->next = NULL;
	return (p);
}

void	ft_clstadd_back(t_clist **lst, t_clist *new)
{
    t_clist *first;
    t_clist *last;

    first = *lst;
	if (first == NULL)
    {
		*lst = new;
        new->next = new;
        new->prev = new;
    }
	else
    {
        last = first->prev;
        last->next = new;
        new->prev = last;
        new->next = first;
        first->prev = new;
    }
}

void	ft_clstadd_front(t_clist **lst, t_clist *new)
{
    ft_clstadd_back(lst, new);
    *lst = new;
}
