SRC = main.cpp Harl.cpp
OBJ = main.o Harl.o
CXX = c++
CXXFLAGS = -Wall -Wextra -Werror -std=c++98 -g3
NAME = harlFilter

all : $(NAME)

$(NAME): $(OBJ)
	$(CXX) $(CXXFLAGS) $(OBJ) -o $(NAME)

clean :
	rm $(OBJ)

fclean : clean
	rm $(NAME)

re : fclean $(NAME)

.PHONY: all clean fclean re
