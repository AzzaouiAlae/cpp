SRC = main.cpp ClapTrap.cpp ScavTrap.cpp FragTrap.cpp DiamondTrap.cpp
OBJ = main.o ClapTrap.o ScavTrap.o FragTrap.o DiamondTrap.o
CXX = c++
CXXFLAGS = -Wall -Wextra -Werror -std=c++98 -Wshadow -Wno-shadow
NAME = diamondTrap

all : $(NAME)

$(NAME): $(OBJ)
	$(CXX) $(CXXFLAGS) $(OBJ) -o $(NAME)

clean :
	rm $(OBJ)

fclean : clean
	rm $(NAME)

re : fclean $(NAME)

.PHONY: all clean fclean re
