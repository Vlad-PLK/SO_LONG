# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vpolojie <vpolojie@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/07/24 18:12:20 by vpolojie          #+#    #+#              #
#    Updated: 2022/11/28 11:14:59 by vpolojie         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long

SRCS = so_long.c ft_check_map_func.c ft_initialize_sprites.c ft_create_map.c ft_free_functions.c \
		ft_display_map.c ft_move_player.c ft_path_finding.c ft_path_finding_part2.c \
		get_next_line/get_next_line.c get_next_line/get_next_line_utils.c


OBJS	= ${SRCS:.c=.o};

CFLAGS = -Wall -Werror -Wextra

MLXFLAGS = -framework OpenGL -framework AppKit

MLX_FOLDER = mlx

LIBFT_FOLDER = libft

PRINTF_FOLDER = printf

INCLUDE = -I./${MLX_FOLDER} -I./${LIBFT_FOLDER} -I./${PRINTF_FOLDER}

LIBRAIRIES = -L./${MLX_FOLDER} -lmlx -L./${LIBFOLDER_LIBFT} -lft -L./${PRINTF_FOLDER} -lftprintf

%.o:		%.c
	gcc ${CFLAGS} ${INCLUDES} -c $< -o $@


$(NAME):	${OBJS}
	@make -s -C ${MLX_FOLDER}
	@echo "\n\033[32mMLX COMPILED SUCCESSFULY\033\n"
	@make -s -C ${PRINTF_FOLDER}
	@echo "\033[32mLIBFT COMPILED SUCCESSFULY\033\n"
	@${CC} ${CFLAGS} $^ ${LIBRAIRIES} ${MLXFLAGS} -o $@
	@echo "\033[32mSO_LONG COMPILED SUCCESSFULY\033\n"

all:		${NAME};

clean:
				@echo "Deleting all object files"
				rm -f ${OBJS}

fclean:		clean
				@echo "\nRemoving ./so_long file"
				rm -f ${NAME}
				@echo "Deleting libft files & .a files"
				rm -f libft/*.o
				rm -f printf/*.o
				rm -f libft/libft.a
				rm -f printf/libftprintf.a

re:				fclean all

.PHONY:		all clean fclean re

