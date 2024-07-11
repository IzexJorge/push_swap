
#include "push_swap.h"

int main(int argc, char *argv[])
{
    t_data  data;

    data.stack_a = NULL;
    data.stack_b = NULL;
    data.stack_a_size = argc - 1;//Cuidado si más adelante considero que puede haber más de un elemento en el mismo arg.
    data.stack_b_size = 0;
    data.bst_root = NULL;
    data.existing_digit_values = NULL;
    data.max_num = get_int(argv[1], &data);
    data.stack_a = get_stack_a(argc, argv, &data);
    free_bst(data.bst_root);
    data.existing_digit_values = get_existing_digit_values(&data);
    sort(&data);
    free_all(&data);
    return (0);
}
