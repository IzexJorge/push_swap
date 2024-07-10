
#include "push_swap.h"

static void push(t_clist **stack_gain, t_clist **stack_lose)
{
    t_clist *first;

    first = *stack_lose;
    if (first == NULL)
        return ;
    if (first->next == first)
        *stack_lose = NULL;
    else
    {
        *stack_lose = first->next;
        first->prev->next = first->next;
        first->next->prev = first->prev;
    }
    ft_clstadd_front(stack_gain, first);
}

void    pa(t_data *data)
{
    push(&(data->stack_a), &(data->stack_b));
    data->operations_count++;
    ft_printf("pa\n");
}

void    pb(t_data *data)
{
    push(&(data->stack_b), &(data->stack_a));
    data->operations_count++;
    ft_printf("pb\n");
}
