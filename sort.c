
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

int get_digit_value(int num, int position)
{
    while (position != 0)
    {
        num /= 10;
        position--;
    }
    num %= 10;
    return (num);
}



// 170, 45, 75, 90, 2, 802, 22, 66

// 170, 90, 2, 802, 22, 45, 75, 66

// 2, 802, 22, 45, 66, 170, 75, 90




// 170, 45, 75, 90, 2, 802, 22, 66

// 66, 75, 45, 22, 802, 2, 90, 170

// 2, 802, 22, 45, 66, 170, 75, 90

void    sort_digit_even(size_t position)
{
    //push_b de 0 a 9
}

void    sort_digit_odd(size_t position)
{
    //push_a de 9 a 0
}


//Me puedo ahorrar el pasar todo del stack_b al stack_a al acabar cada barrido par invirtiendo la lógica de ordenación.
void    sort(t_data *data)
{
    size_t  max_digits;
    size_t  position;

    max_digits = data->max_digits;
    position = 0;
    while (position < max_digits)
    {
        if (position % 2 == 0)
            sort_digit_even(position);
        else
            sort_digit_odd(position);
        position++;
    }
    if (max_digits % 2 == 0)
        full_push_a();
}
