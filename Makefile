# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: marvin <marvin@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/10/11 15:07:17 by eesta            #+#    #+#              #
#    Updated: 2021/10/12 17:36:39 by eesta            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	push_swap
SRC_A		=	push_swap.c push.c liba.c\
				free.c izi.c return.c sort.c\
				rotate.c for_st_a.c for_a_b.c

CC		=	gcc
CFLAG	=	-Wall -Wextra -Werror
CLIB	=	ar -rc
RM		=	rm -f

all:		$(NAME)

$(NAME): $(SRC_A)
	@ $(CC) $(CFLAG) $(SRC_A) -o $(NAME)


clean:
	@ $(RM) $(NAME)

re: fclean all

PHONY: all clean fclean re mandatory bonus
