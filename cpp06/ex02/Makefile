CXX = c++
FLAGS = -Wall -Wextra -Werror -std=c++98

NAME = base

SRC_DIR = sources
HDR_DIR = headers
OBJ_DIR = objects

SOURCES = $(addprefix $(SRC_DIR)/, main.cpp Base.cpp)
HEADERS = $(addprefix $(HDR_DIR)/, Base.hpp A.hpp B.hpp C.hpp)
OBJECTS = $(patsubst $(SRC_DIR)/%.cpp, $(OBJ_DIR)/%.o, $(SOURCES))

all: $(NAME)

$(NAME): Makefile $(OBJECTS)
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
