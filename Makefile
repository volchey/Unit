# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vfil <vfil@student.unit.ua>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/11/13 10:16:29 by vfil              #+#    #+#              #
#    Updated: 2017/11/18 13:08:32 by vchechai         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	fillit

MAIN	=	main.c

SRC		=	ft_count_tetriminos.c ft_read_file.c ft_parse_tetriminos.c \
			ft_check_all.c ft_parse_coord.c ft_shift_tt.c ft_sqrt_mod.c \
			ft_show.c ft_fill.c

FLAGS	=	-Wall -Werror -Wextra

all: $(NAME)

$(NAME):
	@gcc $(FLAGS) $(MAIN) $(SRC) -L. -lft -o $(NAME)

clean:
	@rm -f *.o

fclean: clean
	@rm -f $(NAME)

re: fclean all
