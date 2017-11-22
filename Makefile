# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vfil <vfil@student.unit.ua>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/11/13 10:16:29 by vfil              #+#    #+#              #
#    Updated: 2017/11/22 13:46:20 by vchechai         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	fillit

LIB		=	libfill.a

SRC		=	main.c ft_count_tetriminos.c ft_read_file.c ft_parse_tetriminos.c \
			ft_check_all.c ft_parse_coord.c ft_shift_tt.c ft_sqrt_mod.c \
			ft_show.c ft_fill.c ft_putchar.c ft_putnbr.c ft_putstr.c \
			ft_strcpy.c ft_strnew.c ft_strsub.c ft_bzero.c ft_arriter.c

OSRC	=	$(SRC:.c=.o)

FLAGS	=	-Wall -Werror -Wextra

.PHONY: all clean fclean re
all: $(NAME)

$(NAME): $(OSRC)
	@gcc $(FLAGS) -c $(SRC)
	@ar rc $(LIB) $(OSRC)
	@gcc $(FLAGS) $(SRC) -L. -lfill -o $(NAME)

%.o : %.c
	gcc $(FLAGS) -c $<

clean:
	@rm -f *.o

fclean: clean
	@rm -f $(NAME)

re: fclean all
