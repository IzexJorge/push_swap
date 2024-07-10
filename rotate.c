
#include "push_swap.h"

static void rotate(t_clist **stack)
{
    t_clist *first;

    first = *stack;
    if (first == NULL || first->next == first)
        return ;
    *stack = first->next;
}

void    ra(t_data *data)
{
    rotate(&(data->stack_a));
    data->operations_count++;
    ft_printf("ra\n");
}

void    rb(t_data *data)
{
    rotate(&(data->stack_b));
    data->operations_count++;
    ft_printf("rb\n");
}

void    rr(t_data *data)
{
    rotate(&(data->stack_a));
    rotate(&(data->stack_b));
    data->operations_count++;
    ft_printf("rr\n");
}
