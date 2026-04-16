# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yoshin <yoshin@student.42gyeongsan.kr>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/03/26 18:00:00 by yoshin            #+#    #+#              #
#    Updated: 2026/03/26 18:00:00 by yoshin           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= serialize

SRC_DIR		= .
BUILD_DIR	= build

SRCS		= $(SRC_DIR)/main.cpp \
			  $(SRC_DIR)/Serializer.cpp

HEADERS		= Serializer.hpp \
			  Data.hpp

CXX			= c++
OBJS		= $(SRCS:$(SRC_DIR)/%.cpp=$(BUILD_DIR)/%.o)

CXX			= c++
CXXFLAGS	= -Wall -Wextra -Werror -std=c++98

.PHONY: all clean fclean re dev

all: $(NAME)

$(NAME): $(OBJS)
	$(CXX) $(CXXFLAGS) $(OBJS) -o $(NAME)

$(BUILD_DIR)/%.o: $(SRC_DIR)/%.cpp $(HEADERS)
	@mkdir -p $(dir $@)
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -rf $(BUILD_DIR)

fclean: clean
	rm -f $(NAME)

re: fclean all

dev: CXXFLAGS += -g -DDEBUG
dev: re
