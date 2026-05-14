# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yoshin <yoshin@student.42gyeongsan.kr>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/05/14 15:53:00 by yoshin            #+#    #+#              #
#    Updated: 2026/05/14 15:53:00 by yoshin           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= identify

SRC_DIR		= .
BUILD_DIR	= build

SRCS		= $(SRC_DIR)/main.cpp \
			  $(SRC_DIR)/Base.cpp

OBJS		= $(SRCS:$(SRC_DIR)/%.cpp=$(BUILD_DIR)/%.o)

HEADERS		= Base.hpp

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
