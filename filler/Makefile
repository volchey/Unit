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

SRC     =   ft_parse_map.c ft_get_coord.c ft_set_position.c

FDF_SRC	=	ft_draw_map.c

OBJECTS =   $(patsubst %.c,%.o, ${SRC})

FLAGS	=	-Wall -Wextra -Werror

.PHONY: all clean fclean re

%.o: %.c
	gcc $(FLAGS) -c $< -Ilibft

all: $(NAME)

$(NAME): $(OBJECTS) main.c $(FDF_SRC)
		make -C libft
		gcc $(FLAGS) $(SRC) -I /usr/locale/include main.c $(FDF_SRC) -L \
		/usr/local/lib/ -lmlx -framework OpenGL -framework AppKit \
		-L libft -I libft -lft -o $(NAME)

clean:
	$(MAKE) clean -C libft
	@rm -f *.o

fclean: clean
	$(MAKE) fclean -C libft
	@rm -f $(NAME)

re:
	$(MAKE) re -C libft
	$(MAKE) fclean
	$(MAKE) all
