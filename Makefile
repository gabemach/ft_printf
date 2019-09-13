 # **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gmachado <gmachado@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/05/14 15:46:58 by gmachado          #+#    #+#              #
#    Updated: 2019/09/12 17:25:41 by gmachado         ###   ########.fr        #
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

clean:
	make -C ./includes/libft clean
	rm -f $(OFILES)

fclean: clean
	make -C ./includes/libft fclean
	rm -f $(NAME)

re: fclean all
