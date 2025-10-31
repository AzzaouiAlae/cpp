SRC = main.cpp  newZombie.cpp    Zombie.cpp	randomChump.cpp
OBJ = main.o  newZombie.o    Zombie.o	randomChump.o
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