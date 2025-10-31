SRC = main.cpp Sed.cpp
OBJ = main.o Sed.o
CXX = c++
CXXFLAGS = -Wall -Wextra -Werror -std=c++98 -g3
NAME = replace

all : $(NAME)

$(NAME): $(OBJ)
	$(CXX) $(CXXFLAGS) $(OBJ) -o $(NAME)

clean :
	rm $(OBJ)

fclean : clean
	rm $(NAME)

re : fclean $(NAME)

.PHONY: all clean fclean re
