# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vpolojie <vpolojie@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/07/24 18:12:20 by vpolojie          #+#    #+#              #
#    Updated: 2022/07/28 09:58:23 by vpolojie         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #
NAME = so_long

SRCS = so_long.c \
		printf/libft/ft_putchar_fd.c printf/libft/ft_strdup.c printf/ft_base16.c printf/ft_base16M.c printf/ft_base16UL.c\
		printf/ft_printf.c printf/ft_putnbru.c printf/ft_string.c printf/ft_char.c printf/ft_check_type.c printf/ft_putnbr_fd2.c \
		printf/ft_addr.c printf/libft/ft_isdigit.c printf/ft_nbrdec.c printf/ft_nbrnsigne.c \
		printf/libft/ft_putstr_fd.c printf/ft_nbrtohexa.c printf/ft_nbrtohexamaj.c \
		printf/libft/ft_atoi.c printf/libft/ft_split.c printf/libft/ft_strlen.c printf/libft/ft_strjoin.c \
		get_next_line/get_next_line.c get_next_line/get_next_line_utils.c

OBJS	= ${SRCS:.c=.o};

CFLAGS = -Wall -Werror -Wextra

${NAME}:	${OBJS}
						@gcc ${CFLAGS} -o ${NAME} ${OBJS}

all:		${NAME};

clean:
				rm -f ${OBJS}

fclean:		clean
				rm -f ${NAME}

re:				fclean all

.PHONY:		all clean fclean re

