SRC = tests.cpp Account.cpp
OBJ = tests.o Account.o
CXX = c++
CXXFLAGS = -Wall -Wextra -std=c++98 -g3 -Werror 
NAME = GlobalBanksters

all : $(NAME)

$(NAME): $(OBJ)
	$(CXX) $(CXXFLAGS) $(OBJ) -o $(NAME)

clean :
	rm $(OBJ)

fclean : clean
	rm $(NAME)

re : fclean $(NAME)

.PHONY: all clean fclean re