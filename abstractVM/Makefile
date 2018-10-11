NAME = abstractVM

MAIN = main.cpp

COMP = g++ -std=c++11

SRC = CmdLine.cpp AbstractVM.cpp OperandFactory.cpp Operand.cpp

FLAGS = -Wall -Wextra -Werror

.PHONY: all clean fclean re

all: $(NAME)

$(NAME): $(SRC) $(MAIN)
	$(COMP) $(MAIN) $(SRC) -o $(NAME)

clean:
	@rm -f *.o

fclean: clean
	@rm -f $(NAME)

re: fclean all