# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vchechai <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/06/18 11:00:29 by vchechai          #+#    #+#              #
#    Updated: 2018/06/18 13:57:50 by vchechai         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = ft_retro

FILES = Game.cpp Entity.cpp Asteroid.cpp Field.cpp Player.cpp Rocket.cpp

SRC =   $(addprefix src/, $(FILES))

FLAGS = -Wall -Wextra

.PHONY: all clean fclean re
all: $(NAME)

$(NAME): $(SRC)
	clang++ $(FLAGS) main.cpp $(SRC) -o $(NAME) -lncurses

clean:
	rm -f *.o

fclean:
	make clean
	rm -f $(NAME)

re:
	make fclean
	make all
