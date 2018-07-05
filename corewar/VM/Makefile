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

NAME	=	corewar

MAKE	=	@make

SRC     =   src/*.c

FLAGS	=	-Wall -Wextra -Werror

.PHONY: all clean fclean re
all: $(NAME)

$(NAME): $(SRC) main.c
		@make -C libft
		gcc $(FLAGS) main.c $(SRC) -L libft -lft -o $(NAME)

clean:
	$(MAKE) clean -C libft
	@rm -f *.o

fclean: clean
	$(MAKE) fclean -C libft
	@rm -f $(NAME)

re:
	$(MAKE) fclean
	$(MAKE) all
