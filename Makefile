#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sladonia <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/02/07 15:36:56 by sladonia          #+#    #+#              #
#    Updated: 2017/02/07 15:37:02 by sladonia         ###   ########.fr        #
#                                                                              #
#******************************************************************************#

NAME = minishell
SRC = minishell.c\
		sh_cp_environ.c \
		sh_get_val.c \
		sh_get_exec_path.c \
		sh_get_cmd.c \
		sh_exec_builtin.c \
		sh_get_info.c \
		sh_parse_args.c \
		sh_del_functions.c \
		sh_exit.c \
		sh_unsetenv.c \
		sh_env.c \
		sh_setenv.c \
		sh_echo.c \
		sh_cd.c \
		sh_new_entry.c \
		sh_perror.c \
		sh_get_root_path.c \
		sh_set_val.c \
		sh_get_ch_env.c \
		sh_substitute_env_vars.c
LIB_FT = libft.a
OBJ = $(SRC:.c=.o)
FLG = -Wall -Wextra -Werror
all:    $(NAME)
$(NAME): $(OBJ)
	make -C ./libft
	gcc $(OBJ) -o $(NAME) libft/$(LIB_FT)
%.o: %.c
	gcc -c $(FLG) -o $@ $<
cleanlib:
	make clean -C ./libft
fcleanlib:
	make fclean -C ./libft
clean: cleanlib
	rm -f $(OBJ)
fclean: clean fcleanlib
	rm -f $(NAME)
re: fclean all
