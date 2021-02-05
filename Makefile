# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jna <jna@student.42seoul.kr>               +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/02/01 23:09:50 by jna               #+#    #+#              #
#    Updated: 2021/02/01 23:09:50 by jna              ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	libftprintf.a

CC			=	gcc
CFLAGS		=	-Wall -Wextra -Werror
AR			=	ar rcs
RM			=	rm -f

SRCS		=	get_size_num.c \
				ft_printf.c \
				scan_syntax.c \
				print_num.c \
				convert_and_print.c \
				option.c \
				libft.c \

OBJS	=	${SRCS:.c=.o}

.c.o:
			${CC} ${CFLAGS} -c $< -o ${<:.c=.o}
 
$(NAME):	${OBJS}
			${AR} ${NAME} ${OBJS}

all:		$(NAME)

clean:
			${RM} ${OBJS} ${OBJS_B}

fclean:		clean
			${RM} ${NAME}

re:			fclean all

.PHONY:		all clean fclean re
