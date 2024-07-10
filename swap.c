
#include "push_swap.h"

static void swap(t_clist **stack)
{
    t_clist *first;
    t_clist *second;

    first = *stack;
    if (first == NULL || first->next == first)
        return ;
    second = first->next;
    *stack = second;
    if (first->prev != second)
    {
        first->prev->next = second;
        second->prev = first->prev;
        second->next->prev = first;
        first->next = second->next;
        second->next = first;
        first->prev = second;
    }
}

void    sa(t_data *data)
{
    swap(&(data->stack_a));
    data->operations_count++;
    ft_printf("sa\n");
}

void    sb(t_data *data)
{
    swap(&(data->stack_b));
    data->operations_count++;
    ft_printf("sb\n");
}

void    ss(t_data *data)
{
    swap(&(data->stack_a));
    swap(&(data->stack_b));
    data->operations_count++;
    ft_printf("ss\n");
}
