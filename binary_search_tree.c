
#include "push_swap.h"

static t_tree   *new_node(int value, t_data *data)
{
    t_tree  *node;

    node = malloc(sizeof(t_tree));
    if (node == NULL)
        ft_print_error(data);
    node->value = value;
    node->left = NULL;
    node->right = NULL;
    return (node);
}

static t_tree   *insert(t_tree *node, int value, t_data *data)
{
    if (node == NULL)
        return (new_node(value, data));
    if (value < node->value)
        node->left = insert(node->left, value, data);
    else if (value > node->value)
        node->right = insert(node->right, value, data);
    else
        ft_print_error(data);
    return (node);
}

void    check_duplicates(int num, t_data *data)
{
    data->bst_root = insert(data->bst_root, num, data);
}

void    free_bst(t_tree *node)
{
    if (node == NULL)
        return;
    free_bst(node->left);
    free_bst(node->right);
    free(node);
}
