SRC = main.cpp zombieHorde.cpp Zombie.cpp 
OBJ = main.o zombieHorde.o Zombie.o
CXX = c++
CXXFLAGS = -Wall -Wextra -Werror -std=c++98
NAME = ZombieLand

all : $(NAME)

$(NAME): $(OBJ)
	$(CXX) $(CXXFLAGS) $(OBJ) -o $(NAME)

clean :
	rm $(OBJ)

fclean : clean
	rm $(NAME)

re : fclean $(NAME)

.PHONY: all clean fclean re