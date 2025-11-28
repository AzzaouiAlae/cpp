SRC = main.cpp Bureaucrat.cpp Form.cpp
OBJ = main.o Bureaucrat.o Form.o
CXX = c++
CXXFLAGS = -Wall -Wextra -Werror -std=c++98 -g
NAME = nightmare

all : $(NAME)

$(NAME): $(OBJ)
	$(CXX) $(CXXFLAGS) $(OBJ) -o $(NAME)

clean :
	rm $(OBJ)

fclean : clean
	rm $(NAME)

re : fclean $(NAME)

.PHONY: all clean fclean re