# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vpolojie <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/07/14 11:00:39 by vpolojie          #+#    #+#              #
#    Updated: 2022/07/14 11:01:40 by vpolojie         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

PRINTF = printf/

SRCS = so_long.c

OBJS	= ${SRCS:.c=.o}

NAME = so_long.a

CC		= gcc
RM		= rm -f

CFLAGS = -Wall -Werror -Wextra

.c.o:
			${CC} ${CFLAGS} -c $< -o ${<:.c=.o}

${NAME}:	${OBJS}
						make -C ${PRINTF}
						cp printf/libftprintf.a ${NAME}
						ar src ${NAME} ${OBJS}

all:		${NAME}

clean:
				make clean -C ${PRINTF}
				${RM} ${OBJS}

fclean:		clean
				${RM} ${NAME}
				make fclean -C ${PRINTF}

re:				fclean all

.PHONY:		all clean fclean re

