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

NAME	=	vchechai.filler

MAKE	=	@make

SRC     =   ft_parse_map.c ft_getplayer.c ft_get_coord.c ft_set_position.c

OBJECTS =   $(patsubst %.c,%.o, ${SRC})

FLAGS	=	-Wall -Wextra -Werror

.PHONY: all clean fclean re

%.o: %.c
	gcc $(FLAGS) -c $< -Ilibft

all: $(NAME)

$(NAME): $(OBJECTS) main.c
		make -C libft
		gcc main.c $(SRC) -L libft -I libft -lft -o $(NAME)

clean:
	$(MAKE) clean -C libft
	@rm -f *.o

fclean: clean
	$(MAKE) fclean -C libft
	@rm -f $(NAME)

re:
	$(MAKE) fclean
	$(MAKE) all
