
NAME = push_swap
SRC = push_swap.c \
	push_swap_utils.c \
	circular_list.c \
	binary_search_tree.c \
	get_stack_a.c \
	existing_digit_values.c \
	push.c \
	swap.c \
	rotate.c \
	reverse_rotate.c \
	sort.c \
	

OBJ = $(SRC:.c=.o)
DEPS = $(OBJ) libft/libft.a printf/libftprintf.a push_swap.h
LIBFT = -Llibft -lft
PRINTF = -Lprintf -lftprintf
CC = gcc
CFLAGS = -Wall -Wextra -Werror

.PHONY: all clean fclean re

all: $(NAME)


$(NAME): $(DEPS)
	$(CC) $(CFLAGS) -o $@ $(OBJ) $(LIBFT) $(PRINTF) -g3 -fsanitize=address

libft/libft.a :
	$(MAKE) -C libft -f Makefile

printf/libftprintf.a :
	$(MAKE) -C printf -f Makefile

clean:
	$(MAKE) -C libft -f Makefile clean
	$(MAKE) -C printf -f Makefile clean
	rm -f $(OBJ)

fclean: clean
	$(MAKE) -C libft -f Makefile fclean
	$(MAKE) -C printf -f Makefile fclean
	rm -f $(NAME)

re: fclean all