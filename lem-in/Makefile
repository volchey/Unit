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

NAME	=	lem-in

MAKE	=	@make

SRC     =   parse_rooms.c parse_links.c read_file.c ft_exit.c get_ways.c \
            new_node.c arr_del.c check_ways.c lets_go.c draw_farm.c draw_line.c

FLAGS	=	-Wall -Wextra -Werror

.PHONY: all clean fclean re

%.o: %.c
	gcc -c $< -Ilibft

all: $(NAME)

$(NAME): $(SRC) main.c
		make -C libft
		gcc $(SRC) main.c -lmlx -framework OpenGL -framework AppKit \
                          		-L libft -I libft -lft -o $(NAME)

clean:
	$(MAKE) clean -C libft
	@/bin/rm -f *.o

fclean: clean
	$(MAKE) fclean -C libft
	@rm -f $(NAME)

re:
	$(MAKE) re -C libft
	$(MAKE) fclean
	$(MAKE) all
