# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: fluthra <marvin@42.fr>                       +#+                      #
#                                                    +#+                       #
#    Created: 2026/03/10 17:12:13 by fluthra       #+#    #+#                  #
#    Updated: 2026/04/15 15:41:45 by swetting      ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

SRC = 	adaptive.c \
		base_ops.c \
		benchmark.c \
		chunk_utils.c \
		compute_disorder.c \
		ft_atoi.c \
		ft_bzero.c \
		ft_isdigit.c \
		ft_lstadd_back.c \
		ft_lstadd_front.c \
		ft_lstclear.c \
		ft_lstlast.c \
		ft_lstnew.c \
		ft_lstsecondlast.c \
		ft_lstsize.c \
		ft_putchar_fd.c \
		ft_putendl_fd.c \
		ft_putnbr_fd.c \
		ft_putstr_fd.c \
		ft_strlen.c \
		ft_strncmp.c \
		indexate.c \
		main.c \
		medium.c \
		merge_sort.c \
		print_chunks.c \
		push_largest.c \
		push.c \
		shift_down.c \
		shift_up.c \
		simple.c \
		swap.c \
		utils.c

OBJ = $(SRC:%.c=%.o)

CC = cc

NAME = push_swap

CFlags = -Wall -Wextra -Wall

RM = rm -f

all: $(NAME)

$(NAME):
	$(CC) $(CFlags) $(SRC) -o push_swap

clean:
	$(RM) $(NAME)
	
fclean: clean
	$(RM) $(NAME) &

re: fclean all

.PHONY: all clean fclean re
