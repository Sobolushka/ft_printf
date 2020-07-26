# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: UTurkey <uturkey@student.21-school.ru>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/07/25 22:56:56 by UTurkey           #+#    #+#              #
#    Updated: 2020/07/26 17:36:09 by UTurkey          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC=gcc
OBFLG=-Wall -Wextra -Werror
NAME=libftprintf.a
HEADER =libftprintf.h

SRC=char_repeat.c format_analyze.c ft_printf.c in_array.c print_bigx.c\
	print_x.c print_c.c\
	print_d.c print_p.c print_s.c print_u.c set_default.c ft_strlen.c

OBJ =char_repeat.o format_analyze.o ft_printf.o in_array.o print_bigx.o\
	print_x.o print_c.o\
	print_d.o print_p.o print_s.o print_u.o set_default.o ft_strlen.o

all: $(NAME)

$(NAME): $(OBJ) $(HEADER)
	@$(CC) -c $(SRC) $(OBFLG)
	@ar rc $(NAME) $(OBJ)		
	@ranlib $(NAME)
bonus: all
clean:
	/bin/rm -f *.o
fclean: clean
	/bin/rm -f $(NAME)
re: fclean all