
#include "push_swap.h"

static int get_max_num(t_data *data)
{
    t_clist *node;
    t_clist *first_node;
    int num;
    int max_num;

    node = data->stack_a;
    first_node = node;
    num = *(int *)(node->content);
    max_num = num;
    node = node->next;
    while (node != first_node)
    {
        num = *(int *)(node->content);
        if (num > max_num)
            max_num = num;
        node = node->next;
    }
    return (max_num);
}

static int get_num_existing_digits(t_data *data)
{
    int max_num;
    int num_existing_digits;

    max_num = get_max_num(data);
    num_existing_digits = 0;
    while (max_num != 0)
    {
        max_num /= 10;
        num_existing_digits++;
    }
    return (num_existing_digits);
}

static void    inner_error(int **existing_digit_values, int i, t_data *data)
{
    int j;

    j = 0;
    while (j < i)
    {
        free(existing_digit_values[j]);
        j++;
    }
    free(existing_digit_values);
    ft_print_error(data);
}

int **get_existing_digit_values(t_data *data)
{
    int num_existing_digits;
    int **existing_digit_values;
    int i;
    int *inner_array;

    num_existing_digits = get_num_existing_digits(&data);
    existing_digit_values = malloc((num_existing_digits + 1) * sizeof(int*));
    if (existing_digit_values == NULL)
        ft_print_error(data);
    i = 0;
	while (i < num_existing_digits)
    {
        inner_array = malloc(10 * sizeof(int));
        if (inner_array == NULL)
            inner_error(existing_digit_values, i, data);
        existing_digit_values[i] = inner_array;
        i++;
    }
    existing_digit_values[num_existing_digits] = NULL;
    return (existing_digit_values);
}

int get_digit_exists(t_data *data)
{
    size_t  i;

    i = 0;
    
    return (0);
}
