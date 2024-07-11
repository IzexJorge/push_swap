
#include "push_swap.h"

static int get_num_existing_digits(t_data *data)
{
    int max_num;
    int num_existing_digits;

    max_num = data->max_num;
    num_existing_digits = 0;
    while (max_num != 0)
    {
        max_num /= 10;
        num_existing_digits++;
    }
    return (num_existing_digits);
}

static void inner_error(int **existing_digit_values, int i, t_data *data)
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
    int *digit_array;

    num_existing_digits = get_num_existing_digits(data);
    existing_digit_values = malloc((num_existing_digits + 1) * sizeof(int*));
    if (existing_digit_values == NULL)
        ft_print_error(data);
    i = 0;
	while (i < num_existing_digits)
    {
        digit_array = malloc(10 * sizeof(int));
        if (digit_array == NULL)
            inner_error(existing_digit_values, i, data);
        existing_digit_values[i] = digit_array;
        i++;
    }
    existing_digit_values[num_existing_digits] = NULL;
    fill_existing_digit_values(existing_digit_values, data);
    return (existing_digit_values);
}
