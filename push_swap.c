
#include "push_swap.h"

int main(int argc, char *argv[])
{
    t_data  data;

    data.stack_a = NULL;
    data.stack_b = NULL;
    data.bst_root = NULL;
    data.existing_digit_values = NULL;
    data.stack_a = get_stack_a(argc, argv, &data);
    free_bst(data.bst_root);
    data.existing_digit_values = get_existing_digit_values(&data);
    sort(&data);
    free_all(&data);
    return (0);
}
