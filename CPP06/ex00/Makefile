SRC = main.cpp ScalarConverter.cpp Char.cpp Int.cpp Double.cpp Float.cpp
OBJ = main.o ScalarConverter.o Char.o Int.o Double.o Float.o
CXX = c++
CXXFLAGS = -g3 -Wall -Wextra -Werror -std=c++98 
NAME = converter

all : $(NAME)

$(NAME): $(OBJ)
	$(CXX) $(CXXFLAGS) $(OBJ) -o $(NAME)

clean :
	rm $(OBJ)

fclean : clean
	rm $(NAME)

re : fclean $(NAME)

.PHONY: all clean fclean re
