SRC = main.cpp Bureaucrat.cpp AForm.cpp PresidentialPardonForm.cpp RobotomyRequestForm.cpp ShrubberyCreationForm.cpp Intern.cpp
OBJ = main.o Bureaucrat.o AForm.o PresidentialPardonForm.o RobotomyRequestForm.o ShrubberyCreationForm.o Intern.o
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
