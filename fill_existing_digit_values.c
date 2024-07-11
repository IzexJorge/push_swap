
#include "push_swap.h"

// Gets what value does this digit have in this number.
int get_digit_value(int num, int digit)
{
    while (digit != 0)
    {
        num /= 10;
        digit--;
    }
    num %= 10;
    return (num);
}

// Checks if there is any element in the stack that has this value in this digit.
static int  get_digit_value_exists(int digit, int value, t_data *data)
{
    t_clist *node;
    t_clist *first_node;

    node = data->stack_a;
    first_node = node;
    node = node->next;
    while (node != first_node)
    {
        if (get_digit_value(*(int *)(node->content), digit) == value)
            return (1);
        node = node->next;
    }
    return (0);
}

// Fills the matrix of pseudo boolean values with what values for each digit are present in at least one element of the stack.
// This information will allow us to skip unnecesary iterations of the stack during the Radix sort method.
void    fill_existing_digit_values(int **existing_digit_values, t_data *data)
{
    int digit;
    int *digit_array;
    int value;

    digit = 0;
	digit_array = existing_digit_values[digit];
	while (digit_array != NULL)
	{
        value = 0;
        while (value < 10)
        {
            digit_array[value] = get_digit_value_exists(digit, value, data);
            value++;
        }
		digit++;
		digit_array = existing_digit_values[digit];
	}
}
