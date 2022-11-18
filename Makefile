# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vpolojie <vpolojie@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/07/24 18:12:20 by vpolojie          #+#    #+#              #
#    Updated: 2022/11/18 11:40:16 by vpolojie         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long

SRCS = so_long.c ft_check_map_func.c ft_initialize_sprites.c ft_create_map.c ft_free_functions.c \
		ft_display_map.c ft_move_player.c ft_path_finding.c ft_path_finding_part2.c\
		printf/libft/ft_putchar_fd.c printf/libft/ft_strdup.c printf/ft_base16.c printf/ft_base16M.c printf/ft_base16UL.c\
		printf/ft_printf.c printf/ft_putnbru.c printf/ft_string.c printf/ft_char.c printf/ft_check_type.c printf/ft_putnbr_fd2.c \
		printf/ft_addr.c printf/libft/ft_isdigit.c printf/ft_nbrdec.c printf/ft_nbrnsigne.c \
		printf/libft/ft_putstr_fd.c printf/ft_nbrtohexa.c printf/ft_nbrtohexamaj.c printf/libft/ft_itoa.c \
		printf/libft/ft_atoi.c printf/libft/ft_split.c printf/libft/ft_strlen.c printf/libft/ft_strjoin.c \
		get_next_line/get_next_line.c get_next_line/get_next_line_utils.c


OBJS	= ${SRCS:.c=.o};

CFLAGS = -Wall -Werror -Wextra

MLXFLAGS = -framework OpenGL -framework AppKit

MLX_FOLDER = mlx

INCLUDE = -I./${MLX_FOLDER}

LIBRAIRIES = -L./${MLX_FOLDER} -lmlx


%.o:		%.c
	${CC} ${CFLAGS} ${INCLUDES} -c $< -o $@


$(NAME):	${OBJS}
	make -s -C ${MLX_FOLDER}
	${CC} ${CFLAGS} $^ ${LIBRAIRIES} ${MLXFLAGS} -o $@

all:		${NAME};

clean:
				rm -f ${OBJS}

fclean:		clean
				rm -f ${NAME}

re:				fclean all

.PHONY:		all clean fclean re

