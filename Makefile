# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dpinedo- <dpinedo-@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/12/15 01:31:40 by dpinedo-          #+#    #+#              #
#    Updated: 2024/08/15 14:00:08 by dpinedo-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS_DIR = srcs
#SRCS_DIR_BONUS = srcs_bonus
HEADS_DIR = includes
OBJS_DIR = objs
#OBJS_DIR_BONUS = objs

NAME = webserv
#BONUS_NAME = webserv_bonus

CC = c++ -Wall -Wextra -Werror -std=c++98
CFLAGS = -Wall -Wextra -Werror
CPPFLAGS = -iquote $(HEADS_DIR)
RM = -f

SRCS =	main.cpp\
	initialDefinitions.cpp\
	functions.cpp\
	CheckRcvdRequest.cpp\
	CheckRequestLine.cpp\
	ParseRequest.cpp\
	ParseRequestLine.cpp\
	ParseResponse.cpp\
	ParseStatusLineOut.cpp\
	Method.cpp\
	Get.cpp\
	ParseBodyOut.cpp

#SRCS_BONUS = main_bonus.c\

OBJS = $(SRCS:.cpp=.o)
OBJS_PATH = $(patsubst %.o,$(OBJS_DIR)/%.o,$(OBJS))

#OBJS_BONUS = $(SRCS_BONUS:.cpp=.o)
#OBJS_PATH_BONUS = $(patsubst %.o,$(OBJS_DIR_BONUS)/%.o,$(OBJS_BONUS))

vpath %.cpp $(SRCS_DIR) $(SRCS_DIR_BONUS)
vpath %.o $(OBJS_DIR)

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS_PATH) $(CPPFLAGS) $(LDLFLAGS) -o $@

bonus: $(OBJS_BONUS) $(LIBS)
	$(CC) $(CFLAGS) $(OBJS_PATH_BONUS) $(CPPFLAGS) $(LDLFLAGS) -o $(BONUS_NAME)

%.o: %.cpp
	$(CC) -c $(CFLAGS) $(CPPFLAGS) $< -o $(OBJS_DIR)/$@

clean:
	rm -f $(OBJS_PATH) $(OBJS_PATH_BONUS)

fclean: clean
	rm -f $(NAME) $(BONUS_NAME)

re: fclean all

.PHONY: all clean fclean re
