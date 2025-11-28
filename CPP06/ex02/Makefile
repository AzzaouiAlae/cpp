SRC = main.cpp Base.cpp Type.cpp
OBJ = main.o Base.o Type.o
CXX = c++
CXXFLAGS = -g3 -Wall -Wextra -Werror -std=c++98 
NAME = types

all : $(NAME)

$(NAME): $(OBJ)
	$(CXX) $(CXXFLAGS) $(OBJ) -o $(NAME)

clean :
	rm $(OBJ)

fclean : clean
	rm $(NAME)

re : fclean $(NAME)

.PHONY: all clean fclean re
