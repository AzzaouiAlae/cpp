SRC = main.cpp 
OBJ = main.o 
CXX = c++
CXXFLAGS = -Wall -Wextra -Werror -std=c++98 -Ofast
NAME = PmergeMe

all : $(NAME)

$(NAME): $(OBJ)
	$(CXX) $(CXXFLAGS) $(OBJ) -o $(NAME)

clean :
	rm $(OBJ)

fclean : clean
	rm $(NAME)

re : fclean $(NAME)

.PHONY: all clean fclean re
