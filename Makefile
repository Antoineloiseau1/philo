# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: anloisea <anloisea@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/05 16:52:44 by anloisea          #+#    #+#              #
#    Updated: 2023/01/24 14:48:37 by anloisea         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	philo

SRCS	=	./srcs/main.c \
			./srcs/free.c \
			./srcs/data.c \
			./srcs/threads.c \
			./srcs/time.c \
			./srcs/actions.c \
			./srcs/utils/check_for_errors.c \
			./srcs/utils/small_utils.c \
			./srcs/utils/ft_putstr_fd.c \
			./srcs/utils/ft_atoi.c \
			./srcs/detached_threads.c

OBJS 	=	${SRCS:.c=.o}

CC		=	gcc

CFLAGS	=	-g -Wall -Werror -Wextra -pthread

#DEBUG	=	-fsanitize=thread

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



