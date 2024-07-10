
#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft/libft.h"
# include "printf/ft_printf.h"

typedef struct      s_tree
{
    int             value;
    struct s_tree   *left;
    struct s_tree   *right;
}                   t_tree;

typedef struct      s_clist
{
    void            *content;
    struct s_clist  *next;
    struct s_clist  *prev;
}                   t_clist;

typedef struct  s_data
{
    t_clist     *stack_a;
    t_clist     *stack_b;
    int         operations_count;
    t_tree      *bst_root;
    size_t      max_digits;
    int         **existing_digit_values;
}               t_data;

void	free_all(t_data *data);
void    ft_print_error(t_data *data);
t_clist *ft_clstnew(void *content);
void    ft_clstadd_back(t_clist **lst, t_clist *new);
void	ft_clstadd_front(t_clist **lst, t_clist *new);
void    check_duplicates(int number, t_data *data);
void    free_bst(t_tree *root);
t_clist *get_stack_a(int argc, char *argv[], t_data *data);
int     **get_existing_digit_values(t_data *data);
void    sa(t_data *data);
void    sb(t_data *data);
void    ss(t_data *data);
void    pa(t_data *data);
void    pb(t_data *data);
void    ra(t_data *data);
void    rb(t_data *data);
void    rr(t_data *data);
void    rra(t_data *data);
void    rrb(t_data *data);
void    rrr(t_data *data);

#endif