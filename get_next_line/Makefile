# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vchechai <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/12/01 10:40:02 by vchechai          #+#    #+#              #
#    Updated: 2017/12/02 14:03:55 by vchechai         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = get_next_line

MAIN = main.c

SRC = get_next_line.c

FLAGS = -Wall -Wextra -Werror

.PHONY: all clean fclean re

all: $(NAME)

$(NAME):
	@gcc $(FLAGS) $(MAIN) $(SRC) -L libft -lft -o $(NAME)

clean:
	@rm -f *.o

fclean: clean
	@rm -f $(NAME)

re: fclean all
