SRC = PhoneBook.cpp Contact.cpp PhoneBookCLI.cpp main.cpp
OBJ = PhoneBook.o Contact.o main.o PhoneBookCLI.o
CXX = c++
CXXFLAGS = -Wall -Wextra -Werror -std=c++98 -g3
NAME = AwesomePhoneBook

all : $(NAME)

$(NAME): $(OBJ)
	$(CXX) $(CXXFLAGS) $(OBJ) -o $(NAME)

clean :
	rm $(OBJ)

fclean : clean
	rm $(NAME)

re : fclean $(NAME)

.PHONY: all clean fclean re