SRC = main.cpp ClapTrap.cpp
OBJ = main.o ClapTrap.o
CXX = c++
CXXFLAGS = -Wall -Wextra -Werror -std=c++98
NAME = clapTrap

all : $(NAME)

$(NAME): $(OBJ)
	$(CXX) $(CXXFLAGS) $(OBJ) -o $(NAME)

clean :
	rm $(OBJ)

fclean : clean
	rm $(NAME)

re : fclean $(NAME)

.PHONY: all clean fclean re