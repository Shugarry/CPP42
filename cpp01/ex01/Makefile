NAME = zombie

CXX = c++
FLAGS = -Wall -Wextra -Werror -std=c++98 -I$(HDR_DIR)

SRC_DIR = sources
HDR_DIR = headers
OBJ_DIR = objects

SOURCES = $(addprefix $(SRC_DIR)/, Zombie.cpp main.cpp randomChump.cpp newZombie.cpp zombieHorde.cpp)
HEADERS = $(addprefix $(HDR_DIR)/, Zombie.hpp)
OBJECTS = $(patsubst $(SRC_DIR)/%.cpp,$(OBJ_DIR)/%.o,$(SOURCES))

all: $(NAME)

$(NAME): $(OBJECTS)
	$(CXX) $(FLAGS) $(OBJECTS) -o $(NAME)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp $(HEADERS)
	@mkdir -p $(OBJ_DIR)
	$(CXX) $(FLAGS) -c $< -o $@

clean:
	rm -rf $(OBJ_DIR)

fclean: clean
	rm -f $(NAME)

re: fclean all
	
.PHONY: all clean fclean re
