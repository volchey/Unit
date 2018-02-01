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

SRC		=	ft_putchar.c ft_putstr.c ft_putnbr.c ft_printf.c ft_strjoin.c \
            ft_strcpy.c ft_strdel.c ft_strlen.c ft_strnew.c ft_itoa.c \
            ft_bzero.c set_chr.c set_arg.c ft_chrjoin.c ft_chr_to_str.c \
            ft_set_str.c ft_get_address.c ft_memcpy.c ft_unichar.c ft_power.c \
            ft_unistr.c ft_isdigit.c ft_atoi.c ft_strsub.c ft_isalpha.c \
            ft_isascii.c ft_itoa_base.c get_farg.c \
            ft_lstnew.c ft_lstadd.c ft_unitoa_base.c ft_unitoa_uppbase.c

OSRC	=	$(SRC:.c=.o)

MAKE	=	@make

FLAGS	=	-Wall -Wextra -Werror

.PHONY: all clean fclean re
all: $(NAME)

$(NAME):
	@gcc $(FLAGS) -c $(SRC)
	@ar rc $(NAME) $(OSRC)
	@gcc main.c $(SRC)

clean:
	@rm -f *.o

fclean: clean
	@rm -f $(NAME)

re: 
	$(MAKE) fclean 
	$(MAKE) all
