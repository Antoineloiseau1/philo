# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: anloisea <anloisea@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/05 16:52:44 by anloisea          #+#    #+#              #
#    Updated: 2023/01/09 15:07:41 by anloisea         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	philo

SRCS	=	./srcs/main.c \
			./srcs/threads.c \
			./srcs/free.c \
			./srcs/utils/ft_putstr_fd.c \
			./srcs/utils/ft_atoi.c

OBJS 	=	${SRCS:.c=.o}

CC		=	gcc

CFLAGS	=	-g -Wall -Werror -Wextra -pthread

DEBUG	=	-fsanitize=thread

.c.o:
			${CC} -c ${CFLAGS} $< -o ${<:.c=.o}

all:		${NAME}

${NAME}:	${OBJS}
			${CC} ${DEBUG} ${CFLAGS} ${OBJS} -o ${NAME}

clean:
			rm -rf ${OBJS}

fclean:		clean
			rm -rf ${NAME}

re:			fclean all

.PHONY:		all clean fclean re



