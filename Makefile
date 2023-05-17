# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mmarie <mmarie@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/03/21 01:40:21 by mmarie            #+#    #+#              #
#    Updated: 2023/03/21 13:46:56 by mmarie           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #



SRC = ft_functions.c ft_printf.c ft_prints.c

OBJ = ${SRC:.c=.o}

NAME = libftprintf.a

all : ${NAME}

${NAME}: ${OBJ}
		ar rcs ${NAME} ${OBJ}

.c.o:
		gcc -c -Wall -Wextra -Werror $< -o ${<:.c=.o}

clean:
		rm -f ${OBJ} 

fclean: clean
		rm -f ${NAME}

re: fclean all
