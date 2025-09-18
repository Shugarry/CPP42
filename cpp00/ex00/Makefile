# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: frey-gal <frey-gal@student.42barcelona.co  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/09/18 11:03:42 by frey-gal          #+#    #+#              #
#    Updated: 2025/09/18 11:23:12 by frey-gal         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = megaphone

COMP = c++

CFLAG = -Wall -Wextra -Werror -std=c++98

SRCS = megaphone.cpp

OBJS = $(SRCS:.cpp=.o)

HDRS = \

all: $(NAME)

$(NAME): Makefile $(OBJS) $(HDRS)
	$(COMP) $(CFLAG) $(OBJS) -o $(NAME)

%.o: %.cpp $(HEADERS)
	$(COMP) $(CFLAG) -c $< -o $@

clean:
	rm -rf $(wildcard *.o)

fclean:
	rm -rf $(wildcard *.cpp)

re: fclean all

.PHONY: all clean fclean re
