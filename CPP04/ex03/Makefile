SRC = main.cpp AMateria.cpp Character.cpp Cure.cpp Ice.cpp MateriaSource.cpp
OBJ = main.o AMateria.o Character.o Cure.o Ice.o MateriaSource.o
CXX = c++
CXXFLAGS = -Wall -Wextra -Werror -std=c++98 -g 
NAME = interface

all : $(NAME)

$(NAME): $(OBJ)
	$(CXX) $(CXXFLAGS) $(OBJ)  -o $(NAME)

clean :
	rm $(OBJ)

fclean : clean
	rm $(NAME)

re : fclean $(NAME)

.PHONY: all clean fclean re