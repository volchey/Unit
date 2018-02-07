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

SRC		=	ft_printf.c ft_strcpy.c ft_strdel.c ft_strlen.c ft_strnew.c \
            ft_itoa.c ft_bzero.c set_arg.c ft_chrjoin.c ft_set_str.c \
            ft_get_address.c ft_memcpy.c ft_unichar.c ft_power.c ft_unistr.c \
            ft_isdigit.c ft_atoi.c ft_strsub.c get_farg.c ft_set_chr.c \
            ft_isupper.c ft_lstnew.c ft_lstadd.c ft_unitoa_base.c \
            ft_unitoa_uppbase.c \

OSRC	=	$(SRC:.c=.o)

MAKE	=	@make

FLAGS	=	-Wall -Wextra -Werror

.PHONY: all clean fclean re
all: $(NAME)

$(NAME):
	@gcc $(FLAGS) -c $(SRC)
	@ar rc $(NAME) $(OSRC)

%.o : %.c
	@gcc $(FLAGS) -c $<

clean:
	@/bin/rm -f *.o

fclean: clean
	@/bin/rm -f $(NAME)

re:
	$(MAKE) fclean
	$(MAKE) all
