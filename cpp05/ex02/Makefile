NAME = Bureaucrat
FLAGS = c++ -Wall -Werror -Wextra -std=c++98

SRC = main.cpp \
		Bureaucrat.cpp \
		AForm.cpp \
		ShrubberyCreationForm.cpp \
		RobotomyRequestForm.cpp \
		PresidentialPardonForm.cpp

OBJECTS		= $(SRC:.cpp=.o)

all:
	@$(MAKE) $(NAME)

$(NAME): $(OBJECTS)
	@$(FLAGS) $(OBJECTS) -o $(NAME)

clean:
	@rm -rf *.o
	@rm -rf *.shrubbery

fclean: clean
	@rm -f $(NAME)

re: fclean all
.PHONY: all clean fclean re
