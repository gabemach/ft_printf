 # **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gmachado <gmachado@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/05/14 15:46:58 by gmachado          #+#    #+#              #
#    Updated: 2019/08/21 16:58:51 by gmachado         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

CFILES = $(wildcard ./srcs/*.c)

OFILES = *.o

CFLAGS = -Wall -Wextra -Werror -c -g

INCLUDES = -L ./includes/libft

HEADER = -I ./srcs/ft_printf.h

all: $(NAME)

$(NAME): $(CFILES)
	make -C ./includes/libft
	gcc $(CFLAGS) $(CFILES)
	ar rc $(NAME) $(OFILES) ./includes/libft/*.o
	ranlib $(NAME)
	# gcc $(CFLAGS) -I ./srcs/ft_printf.h $(HEADER) -c $(CFILES)
#	ar rc $(NAME) $(OFILES)
#	ranlib $(NAME)
	# gcc $(CFLAGS) -I ./srcs/ft_printf.h -o ft_printf.o -c ./srcs/ft_printf.c
	# gcc $(CFLAGS) -I ./srcs/ft_printf.h -o ft_uitoa.o -c ./srcs/ft_uitoa.c
	# gcc $(CFLAGS) -I ./srcs/ft_printf.h -o conversions.o -c ./srcs/conversions.c
	# gcc $(CFLAGS) -I ./srcs/ft_printf.h -o parsing.o -c ./srcs/parsing.c
	# gcc $(CFLAGS) -I ./srcs/ft_printf.h -o initializer.o -c ./srcs/initializer.c
	# gcc $(CFLAGS) -I ./srcs/ft_printf.h -o write_sc.o -c ./srcs/write_sc.c
	# gcc $(CFLAGS) -I ./srcs/ft_printf.h -o write_misc.o -c ./srcs/write_misc.c
	# gcc $(CFLAGS) -I ./srcs/ft_printf.h -o write_si.o -c ./srcs/write_si.c
	# gcc $(CFLAGS) -I ./srcs/ft_printf.h -o write_p.o -c ./srcs/write_p.c
	# gcc $(CFLAGS) -I ./srcs/ft_printf.h -o write_ui.o -c ./srcs/write_ui.c
	# gcc $(CFLAGS) -I ./srcs/ft_printf.h -o write_float.o -c ./srcs/write_float.c
	# gcc $(CFLAGS) -I ./srcs/ft_printf.h -o fassist.o -c ./srcs/fassist.c
	# gcc $(CFLAGS) -o $(NAME) write_float.o fassist.o write_ui.o write_p.o write_si.o ft_printf.o write_sc.o initializer.o parsing.o ft_uitoa.o conversions.o write_misc.o -L ./includes/libft -lft

clean:
	make -C ./includes/libft clean
	rm -f $(OFILES)

fclean: clean
	make -C ./includes/libft fclean
	rm -f $(NAME)

re: fclean all
