# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vchechai <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/11/06 11:14:54 by vchechai          #+#    #+#              #
#    Updated: 2017/11/09 11:22:54 by vchechai         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	libft.a

SRC		=	ft_memset.c ft_bzero.c ft_memcpy.c ft_memccpy.c ft_memmove.c \
			ft_memchr.c ft_memcmp.c ft_strlen.c ft_strdup.c ft_strcpy.c \
			ft_strncpy.c ft_strcat.c get_next_line.c ft_sqrt.c ft_arrlen.c \
			ft_strncat.c ft_strlcat.c ft_strchr.c ft_strrchr.c ft_strstr.c \
			ft_strnstr.c ft_strcmp.c ft_strncmp.c ft_atoi.c ft_isalpha.c \
			ft_isdigit.c ft_isalnum.c ft_isascii.c ft_isprint.c ft_toupper.c \
			ft_tolower.c ft_memalloc.c ft_memdel.c ft_strnew.c ft_strdel.c \
			ft_strclr.c ft_striter.c ft_striteri.c ft_strmap.c ft_strmapi.c \
			ft_itoa.c ft_putchar.c ft_putstr.c ft_putendl.c \
			ft_putnbr.c ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c \
			ft_strequ.c ft_strnequ.c ft_strsub.c ft_strjoin.c ft_strtrim.c \
			ft_strsplit.c ft_putnbr_fd.c ft_lstnew.c ft_lstdelone.c \
			ft_lstdel.c \
			ft_lstadd.c ft_lstiter.c ft_lstmap.c ft_count_word.c \
			ft_isupper.c ft_islower.c ft_strlwr.c ft_strupr.c

OSRC	=	$(SRC:.c=.o)

PF_SRC	=	ft_printf.c ft_itoa_pf.c set_arg.c ft_chrjoin.c ft_set_str.c \
			ft_get_address.c ft_unichar.c ft_power.c ft_unistr.c \
			get_farg.c ft_set_chr.c \
			ft_unitoa_base.c \
			ft_unitoa_uppbase.c ft_numlen.c \

SRC_PF	=	$(addprefix ft_printf/, $(PF_SRC))

PF_OSRC	=	$(PF_SRC:.c=.o)

MAKE	=	@make

FLAGS	=	-Wall -Wextra -Werror

%.o: %.c
	gcc $(FLAGS) -c $<

.PHONY: all clean fclean re

all: $(NAME)

$(NAME): $(SRC) $(SRC_PF)
	@gcc $(FLAGS) -c $(SRC)
	@gcc $(FLAGS) -c $(SRC_PF)
	@ar rc $(NAME) $(OSRC) $(PF_OSRC)

clean:
	@rm -f *.o

fclean: clean
	@rm -f $(NAME)

re: 
	$(MAKE) fclean 
	$(MAKE) all
