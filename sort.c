
#include "push_swap.h"

//Primero determinar el índice de cada elemento sin restricciones y después
//conseguir ese orden con las operaciones permitidas.

//Tal vez crear una lista enlazada que contenga los índices de los elementos del array ordenados.
//Cada vez que se introduce un elemento se checkea si es mayor, menor o igual
//que el elemento al que el ínfice de cada nodo apunta. Si es mayor, se pasa
//al siguiente nodo, si es menor, se crea un nuevo nodo con el índice del
//elemento introducido y se sitúa entre el nodo anterior y el actual.

//Después, sustituir en el array cada elemento por su índice ordenado, determinado por el estado final de la lista enlazada.



// Dado que la primera prioridad es minimizar el número de operaciones y el tiempo de ejecución sólo debe no llegar a un límite,
// puedo hallar qué valores por cada dígito no están presentes en ningún elemento para omitir sus barridos correspondientes. Se guardan en un array bidimensional de enteros.
// También puedo hallar el número de dígitos del mayor número para omitir el resto de dígitos, que son 0 en todos los números.
// Una vez ordenados ignorando el signo, hacer lo mismo pero en función de si tiene signo o no y en orden inverso, ya que cuanto mayor es un número sin signo negativo, menor es con él.





// 170, 45, 75, 90, 2, 802, 22, 66

// 170, 90, 2, 802, 22, 45, 75, 66

// 2, 802, 22, 45, 66, 170, 75, 90




// 170, 45, 75, 90, 2, 802, 22, 66

// 66, 75, 45, 22, 802, 2, 90, 170

// 2, 802, 22, 45, 66, 170, 75, 90



//Dado que lo que importa es lo que se printea, el estado final de los stacks en el programa da igual y por lo tanto podemos simplemente printar "pa" un número igual al de elemenos introducidos al programa.
static void full_push_a(t_data *data)
{
    int stack_b_size;
    int i;

    stack_b_size = data->stack_b_size;
    i = 0;
    while (i < stack_b_size)
    {
        data->operations_count++;
        ft_printf("pa\n");
        i++;
    }
}

static void push(int is_stack_a, t_data *data)
{
    if (is_stack_a)
        pa(data);
    else
        pb(data);
}

static void push_digit_value(int is_stack_a, int digit, int value, t_data *data)
{
    t_clist **stack;
    int stack_size;
    int i;
    t_clist *top_node;

    if (is_stack_a)
    {
        stack = &(data->stack_a);
        stack_size = data->stack_a_size;
    }
    else
    {
        stack = &(data->stack_b);
        stack_size = data->stack_b_size;
    }
    i = 0;
    while (i < stack_size)
    {
        top_node = *stack;
        if (get_digit_value(*(int *)(top_node->content), digit) == value)
            push(is_stack_a, data);
        else
            rotate(is_stack_a, data);
        i++;
    }
}

static void sort_digit(int digit, int *digit_array, t_data *data)
{
    int value;

    if (digit % 2 == 0)
    {
        value = 0;
        while (value <= 9)
        {
            if (digit_array[value] == 1)
                push_digit_value(1, digit, value, data);
            value++;
        }
    }
    else
    {
        value = 9;
        while (value >= 0)
        {
            if (digit_array[value] == 1)
                push_digit_value(0, digit, value, data);
            value--;
        }
    }
}

//Me puedo ahorrar el pasar todo del stack_b al stack_a al acabar cada barrido par invirtiendo la lógica de ordenación.
void    sort(t_data *data)
{
    int digit;
    int **existing_digit_values;
    int *digit_array;

    digit = 0;
    existing_digit_values = data->existing_digit_values;
	digit_array = existing_digit_values[digit];
	while (digit_array != NULL)
	{
        sort_digit(digit, digit_array, data);
		digit++;
		digit_array = existing_digit_values[digit];
	}
    if (digit % 2 != 0)
        full_push_a(data);
}
