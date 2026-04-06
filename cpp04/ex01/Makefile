CXX = c++
FLAGS = -Wall -Wextra -Werror -std=c++98

NAME = animal

SRC_DIR = sources
HDR_DIR = headers
OBJ_DIR = objects

SOURCES = $(addprefix $(SRC_DIR)/, main.cpp Animal.cpp Cat.cpp Dog.cpp \
		  WrongAnimal.cpp WrongCat.cpp)
HEADERS = $(addprefix $(HDR_DIR)/, Animal.hpp Cat.hpp Dog.hpp \
		  WrongAnimal.hpp WrongCat.hpp)
OBJECTS = $(patsubst $(SRC_DIR)/%.cpp,$(OBJ_DIR)/%.o,$(SOURCES))

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
