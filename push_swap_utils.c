
#include "push_swap.h"

//TODO Crear lstclear para circulares.
static void	free_stacks(t_data *data)
{
	ft_lstclear(&(data->stack_a), free);
	ft_lstclear(&(data->stack_b), free);
}

static void	free_existing_digit_values(t_data *data)
{
	int	**existing_digit_values;
	int	digit;
	int	*digit_array;

	existing_digit_values = data->existing_digit_values;
	if (existing_digit_values == NULL)
		return;
	digit = 0;
	digit_array = existing_digit_values[digit];
	while (digit_array != NULL)
	{
		free(digit_array);
		digit++;
		digit_array = existing_digit_values[digit];
	}
	free(existing_digit_values);
}

void	free_all(t_data *data)
{
	free_stacks(data);
	free_bst(data->bst_root);
	free_existing_digit_values(data);
}

void	ft_print_error(t_data *data)
{
	free_all(data);
	write(2, "Error\n", 6);
	exit(1);
}

// void	check_duplicates(t_list *stack_a, t_data *data)
// {
// 	t_list	*current;
// 	t_list	*remaining;

// 	current = stack_a;
// 	while (current)
// 	{
// 		remaining = current->next;
// 		while (remaining)
// 		{
// 			if (*(int *)(current->content) == *(int *)(remaining->content))
// 				ft_print_error(data);
// 			remaining = remaining->next;
// 		}
// 		current = current->next;
// 	}
// }
