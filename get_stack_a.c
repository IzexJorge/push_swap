
#include "push_swap.h"

int  get_int(char *str, t_data *data)
{
    int         sign;
    size_t      i;
    long long   num;

    sign = 1;
    i = 0;
    if (str[i] == '-' || str[i] == '+')
    {
        if (str[i] == '-')
            sign = -1;
        i++;
    }
    num = 0;
    while (str[i])
    {
        if (ft_isdigit(str[i]) == NULL)
            ft_print_error(data);
        num *= 10;
        num += str[i] - '0';
        i++;
    }
    num *= sign;
    if (num != (int)num)
        ft_print_error(data);
    return ((int)num);
}

static int  *get_int_ptr(char *str, t_data *data)
{
    int num;
    int *p;

    num = get_int(str, data);
    check_duplicates(num, data);
    if (num > data->max_num)
        data->max_num = num;
    p = malloc(sizeof(int));
    if (p == NULL)
        ft_print_error(data);
    *p = num;
    return (p);
}

t_clist   *get_stack_a(int argc, char *argv[], t_data *data)
{
    t_clist  *stack_a;
    t_clist  *new_node;
    size_t  i;

    if (argc < 2)
        exit(0);
    stack_a = NULL;
    i = 1;
    while (argv[i])
    {
        new_node = ft_clstnew(get_int_ptr(argv[i], data));
        if (new_node == NULL)
            ft_print_error(data);
        ft_clstadd_back(&stack_a, new_node);
        i++;
    }
    //check_duplicates(stack_a, data);
    return (stack_a);
}