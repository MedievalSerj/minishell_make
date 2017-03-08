#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sladonia <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/12/02 15:30:11 by sladonia          #+#    #+#              #
#    Updated: 2016/12/02 15:30:14 by sladonia         ###   ########.fr        #
#                                                                              #
#******************************************************************************#

NAME = libft.a
SRC =  ft_atoi.c \
		ft_bzero.c \
		ft_char_n_str.c \
		ft_isalnum.c \
		ft_isalpha.c \
		ft_isascii.c \
		ft_isdigit.c \
		ft_isprint.c \
		ft_itoa.c \
		ft_lstadd.c \
		ft_lstdel.c \
		ft_lstdelone.c \
		ft_lstiter.c \
		ft_lstmap.c \
		ft_lstnew.c \
		ft_memalloc.c \
		ft_memccpy.c \
		ft_memchr.c \
		ft_memcmp.c \
		ft_memcpy.c \
		ft_memdel.c \
		ft_memmove.c \
		ft_memset.c \
		ft_print_width.c \
		ft_putchar.c \
		ft_putchar_fd.c \
		ft_putendl.c \
		ft_putendl_fd.c \
		ft_putnbr.c \
		ft_putnbr_fd.c \
		ft_putstr.c \
		ft_putstr_fd.c \
		ft_str_tolower.c \
		ft_strcat.c \
		ft_strchr.c \
		ft_strclr.c \
		ft_strcmp.c \
		ft_strcpy.c \
		ft_strdel.c \
		ft_strdup.c \
		ft_strequ.c \
		ft_striter.c \
		ft_striteri.c \
		ft_strjoin.c \
		ft_strlcat.c \
		ft_strlen.c \
		ft_strmap.c \
		ft_strmapi.c \
		ft_strncat.c \
		ft_strncmp.c \
		ft_strncpy.c \
		ft_strnequ.c \
		ft_strnew.c \
		ft_strnstr.c \
		ft_strrchr.c \
		ft_strsplit.c \
		ft_strstr.c \
		ft_strsub.c \
		ft_strtrim.c \
		ft_tolower.c \
		ft_toupper.c \
		get_next_line.c \
		c_char.c \
		d_signed_decimal.c \
		definitions.c \
		fill_struct.c \
		ft_str_append.c \
		ft_str_append_unsafe.c \
		ft_str_hex.c \
		ft_str_long.c \
		ft_str_u_long.c \
		ft_utf.c \
		o_octal.c \
		p_hex.c \
		persent.c \
		s_string.c \
		select.c \
		u_unsigned_decimal.c \
		validate_size.c \
		wc_char.c \
		ws_string.c \
		x_hex.c \
		ft_printf.c \
		ft_str_j.c \
		buffered_reader.c \
		ft_readline.c \
		get_num_str.c \
		ft_list_dir.c \
		l_add.c \
		l_del.c \
		l_del_all.c \
		l_del_nth.c \
		l_get_nth.c \
		l_iter.c \
		l_count.c \
		l_add_last.c \
		ft_clear_array.c \
		ft_char_last_n.c \
		ft_reasign.c \
		ft_lst_to_arr.c \
		ft_lst_print_str.c
OBJ = $(SRC:.c=.o)
HEADER = libft.h
CC = gcc
CFLAGS = -c -Wall -Wextra -Werror
all: $(NAME)
$(NAME): $(OBJ)
		ar rc $(NAME) $(OBJ)
		ranlib $(NAME)
%.o: %.c $(HEADER)
		$(CC) $(CFLAGS) -o $@ $<
clean:
		rm -f $(OBJ)
fclean: clean
		rm -f $(NAME)
re: fclean all