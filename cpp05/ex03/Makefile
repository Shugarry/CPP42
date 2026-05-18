CXX = c++
FLAGS = -Wall -Wextra -Werror -std=c++98

NAME = bureaucrat

SRC_DIR = sources
HDR_DIR = headers
OBJ_DIR = objects

SOURCES = $(addprefix $(SRC_DIR)/, main.cpp Bureaucrat.cpp AForm.cpp Intern.cpp\
		  ShrubberyCreationForm.cpp PresidentialPardonForm.cpp RobotomyRequestForm.cpp)
HEADERS = $(addprefix $(HDR_DIR)/, Bureaucrat.hpp AForm.hpp Intern.hpp\
		  ShrubberyCreationForm.hpp PresidentialPardonForm.hpp RobotomyRequestForm.hpp)
OBJECTS = $(patsubst $(SRC_DIR)/%.cpp, $(OBJ_DIR)/%.o, $(SOURCES))

all: $(NAME)

$(NAME): $(OBJECTS) Makefile
	$(CXX) $(FLAGS) $(OBJECTS) -o $(NAME)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp $(HEADERS)
	@mkdir -p $(OBJ_DIR)
	$(CXX) $(FLAGS) -c $< -o $@

clean:
	rm -rf $(OBJ_DIR)

fclean: clean
	rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re
