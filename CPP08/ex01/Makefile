SRC = main.cpp Span.cpp
OBJ = main.o Span.o
CXX = c++
CXXFLAGS = -g3 -Wall -Wextra -Werror -std=c++98 
NAME = span

all : $(NAME)

$(NAME): $(OBJ)
	$(CXX) $(CXXFLAGS) $(OBJ) -o $(NAME)

clean :
	rm $(OBJ)

fclean : clean
	rm $(NAME)

re : fclean $(NAME)

.PHONY: all clean fclean re
