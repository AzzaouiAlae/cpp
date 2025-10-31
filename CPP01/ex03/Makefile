SRC = main.cpp HumanA.cpp HumanB.cpp Weapon.cpp
OBJ = main.o HumanA.o HumanB.o Weapon.o
CXX = c++
CXXFLAGS = -Wall -Wextra -Werror -std=c++98 -g3
NAME = HumanViolence

all : $(NAME)

$(NAME): $(OBJ)
	$(CXX) $(CXXFLAGS) $(OBJ) -o $(NAME)

clean :
	rm $(OBJ)

fclean : clean
	rm $(NAME)

re : fclean $(NAME)

.PHONY: all clean fclean re
