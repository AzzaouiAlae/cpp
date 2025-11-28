SRC = main.cpp Animal.cpp Dog.cpp Cat.cpp WrongCat.cpp WrongAnimal.cpp
OBJ = main.o Animal.o Dog.o Cat.o WrongCat.o WrongAnimal.o
CXX = c++
CXXFLAGS = -Wall -Wextra -Werror -std=c++98
NAME = animal

all : $(NAME)

$(NAME): $(OBJ)
	$(CXX) $(CXXFLAGS) $(OBJ) -o $(NAME)

clean :
	rm $(OBJ)

fclean : clean
	rm $(NAME)

re : fclean $(NAME)

.PHONY: all clean fclean re