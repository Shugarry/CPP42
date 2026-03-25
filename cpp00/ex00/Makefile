NAME = megaphone

CXX = c++
FLAGS = -Wall -Wextra -Werror -std=c++98
#-I$(HDR_DIR)

SRC_DIR = sources
OBJ_DIR = objects
#HDR_DIR = headers

SOURCES = $(addprefix $(SRC_DIR)/, megaphone.cpp)
#HEADERS = $(addprefix $(HDR_DIR)/, megaphone.hpp)
OBJECTS = $(patsubst $(SRC_DIR)/%.cpp,$(OBJ_DIR)/%.o,$(SOURCES))

all: $(NAME)

$(NAME): Makefile $(OBJECTS)
	$(CXX) $(FLAGS) $(OBJECTS) -o $(NAME)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp #$(HEADERS)
	@mkdir -p $(OBJ_DIR)
	$(CXX) $(FLAGS) -c $< -o $@

clean:
	rm -rf $(OBJ_DIR)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
