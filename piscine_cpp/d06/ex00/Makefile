# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vchechai <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/06/18 11:00:29 by vchechai          #+#    #+#              #
#    Updated: 2018/06/18 11:08:18 by vchechai         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = program

SRC = main.cpp

FLAGS = -Wall -Wextra -Werror

.PHONY: all clean fclean re
all: $(NAME)

$(NAME): $(SRC)
	clang++ $(FLAGS) $(SRC) -o $(NAME)

clean:
	rm -f *.o

fclean:
	make clean
	rm -f $(NAME)

re:
	make fclean
	make all
