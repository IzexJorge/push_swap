
#include "push_swap.h"

static void reverse_rotate(t_clist **stack)
{
    t_clist *first;

    first = *stack;
    if (first == NULL || first->next == first)
        return ;
    *stack = first->prev;
}

void    rra(t_data *data)
{
    reverse_rotate(&(data->stack_a));
    data->operations_count++;
    ft_printf("rra\n");
}

void    rrb(t_data *data)
{
    reverse_rotate(&(data->stack_b));
    data->operations_count++;
    ft_printf("rrb\n");
}

void    rrr(t_data *data)
{
    reverse_rotate(&(data->stack_a));
    reverse_rotate(&(data->stack_b));
    data->operations_count++;
    ft_printf("rrr\n");
}
