# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vchechai <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/12/01 10:40:02 by vchechai          #+#    #+#              #
#    Updated: 2017/12/16 16:18:11 by vchechai         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = get_next_line

MAIN = main.c

SRC = get_next_line.c

FLAGS = -Wall -Wextra -Werror -g -fsanitize=address 

.PHONY: all clean fclean re

all: $(NAME)

$(NAME):
	@gcc $(FLAGS) $(MAIN) $(SRC) -L libft -lft -o $(NAME)

clean:
	@rm -f *.o

fclean: clean
	@rm -f $(NAME)

re: fclean all
