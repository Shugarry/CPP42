CXX = c++
FLAGS = -Wall -Wextra -Werror -std=c++98

NAME = brain

SRC_DIR = sources
OBJ_DIR = objects

SOURCES = $(addprefix $(SRC_DIR)/, main.cpp)
OBJECTS = $(patsubst $(SRC_DIR)/%.cpp,$(OBJ_DIR)/%.o,$(SOURCES))

all: $(NAME)

$(NAME): $(OBJECTS) Makefile
	$(CXX) $(FLAGS) $(OBJECTS) -o $(NAME)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp
	@mkdir -p objects
	$(CXX) $(FLAGS) -c $< -o $@

clean:
	rm -rf objects

fclean: clean
	rm $(NAME)

re: fclean all

.PHONY: all clean fclean re
