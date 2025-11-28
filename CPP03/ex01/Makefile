SRC = main.cpp ClapTrap.cpp ScavTrap.cpp
OBJ = main.o ClapTrap.o ScavTrap.o
CXX = c++
CXXFLAGS = -Wall -Wextra -Werror -std=c++98 -g
NAME = scavTrap

all : $(NAME)

$(NAME): $(OBJ)
	$(CXX) $(CXXFLAGS) $(OBJ) -o $(NAME)

clean :
	rm $(OBJ)

fclean : clean
	rm $(NAME)

re : fclean $(NAME)

.PHONY: all clean fclean re