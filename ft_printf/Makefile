# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vchechai <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/11/06 11:14:54 by vchechai          #+#    #+#              #
#    Updated: 2018/01/11 17:00:26 by vchechai         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	libftprintf.a

SRC		=	ft_putchar.c ft_putstr.c ft_putnbr.c ft_printf.c set_integer.c \
			ft_strjoin.c ft_strcpy.c ft_strdel.c ft_strlen.c ft_strnew.c \
			ft_itoa.c ft_bzero.c set_chr.c

OSRC	=	$(SRC:.c=.o)

MAKE	=	@make

FLAGS	=	-Wall -Wextra -Werror

.PHONY: all clean fclean re
all: $(NAME)

$(NAME):
	@gcc $(FLAGS) -c $(SRC)
	@ar rc $(NAME) $(OSRC)
	@gcc $(FLAGS) main.c $(SRC)

clean:
	@rm -f *.o

fclean: clean
	@rm -f $(NAME)

re: 
	$(MAKE) fclean 
	$(MAKE) all
