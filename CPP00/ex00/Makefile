SRC = megaphone.cpp
OBJ = megaphone.o
CXX = c++
CFLAGS = -Wall -Wextra -Werror -std=c++98
NAME = megaphone

all : $(NAME)

$(NAME): $(OBJ)
	$(CXX) $(CFLAGS) $(OBJ) -o $(NAME)

clean :
	rm $(OBJ)

fclean : clean
	rm $(NAME)

re : fclean $(NAME)

.PHONY: all clean fclean re