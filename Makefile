# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: douglas <douglas@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/03/20 09:25:40 by dengstra          #+#    #+#              #
#    Updated: 2017/07/13 14:36:59 by dengstra         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

SRC = ft_atoi.c	\
	  ft_print_color.c	\
	  btree_get_nth.c	\
	  btree_num_nodes.c	\
	  ft_print_till.c	\
	  ft_memdup.c		\
	  ft_free_list.c	\
	  btree_free.c		\
	  btree_apply_infix.c \
	  btree_apply_prefix.c \
	  btree_apply_suffix.c \
	  btree_create_node.c \
	  btree_insert.c \
	  btree_search_item.c \
	  ft_split_len.c	\
	  ft_free_split.c	\
	  ft_lstadd_rev.c	\
	  ft_strcpytill.c	\
	  ft_only_char.c	\
	  ft_strndup.c		\
	  get_next_line.c	\
	  ft_is_int.c		\
	  ft_strjoinfree.c \
	  ft_putstrfree.c \
	  ft_strndup.c	\
	  ft_arrayrev.c \
	  ft_itoa_base.c	\
	  ft_foreach.c	\
	  ft_strrev.c	\
	  ft_sort_integer_table.c	\
	  ft_sqrt.c	\
	  ft_swap.c	\
	  ft_bzero.c	\
	  ft_isalnum.c	\
	  ft_isalpha.c	\
	  ft_isascii.c	\
	  ft_isdigit.c	\
	  ft_isprint.c	\
	  ft_itoa.c	\
	  ft_lstadd.c	\
	  ft_lstdel.c	\
	  ft_lstdelone.c	\
	  ft_lstiter.c	\
	  ft_lstmap.c	\
	  ft_lstnew.c	\
	  ft_memalloc.c	\
	  ft_memccpy.c	\
	  ft_memchr.c	\
	  ft_memcmp.c	\
	  ft_memcpy.c	\
	  ft_memdel.c	\
	  ft_memmove.c	\
	  ft_memset.c	\
	  ft_putchar.c	\
	  ft_putchar_fd.c	\
	  ft_putendl.c	\
	  ft_putendl_fd.c	\
	  ft_putnbr.c	\
	  ft_putnbr_fd.c	\
	  ft_putstr.c	\
	  ft_putstr_fd.c	\
	  ft_sort_integer_table.c	\
	  ft_strcat.c	\
	  ft_strchr.c	\
	  ft_strclr.c	\
	  ft_strcmp.c	\
	  ft_strcpy.c	\
	  ft_strdel.c	\
	  ft_strdup.c	\
	  ft_strequ.c	\
	  ft_striter.c	\
	  ft_striteri.c	\
	  ft_strjoin.c	\
	  ft_strlcat.c	\
	  ft_strlen.c	\
	  ft_strmap.c	\
	  ft_strmapi.c	\
	  ft_strncat.c	\
	  ft_strncmp.c	\
	  ft_strncpy.c	\
	  ft_strnequ.c	\
	  ft_strnew.c	\
	  ft_strnstr.c	\
	  ft_strrchr.c	\
	  ft_strsplit.c	\
	  ft_strstr.c	\
	  ft_strsub.c	\
	  ft_strtrim.c	\
	  ft_tolower.c	\
	  ft_toupper.c	\
	  ft_printf/ft_printf.c	\
	  ft_printf/bytes.c	\
	  ft_printf/get_flags.c	\
	  ft_printf/input_checker.c	\
	  ft_printf/is_id.c	\
	  ft_printf/length_converter.c	\
	  ft_printf/padding.c	\
	  ft_printf/printer.c	\
	  ft_printf/printnbr.c	\
	  ft_printf/printstr.c	\
	  ft_printf/putwstr.c

SRCO = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(SRCO)
	ar rc $(NAME) $(SRCO)

%.o: %.c
	@gcc -c $(FLAGS) $< -o $@

clean:
	/bin/rm -f $(SRCO)

fclean: clean
	/bin/rm -f $(NAME)

re: fclean all
