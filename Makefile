# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ahinani <ahinani@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/01/19 12:28:28 by ahinani           #+#    #+#              #
#    Updated: 2022/02/16 14:28:20 by ahinani          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = server
CLIENT = client

NAME_B = server_bonus
CLIENT_B = client_bonus

FLAGS = -Wall -Wextra -Werror
CC = gcc
RM = rm -rf

SRC = 	client.c			\
		server.c 			\
		client_bonus.c		\
		server_bonus.c

TOOLS = tools.c

CLIENT_SRC = client.c
CLIENT_B_SRC = client_bonus.c

SERVER_SRC = server.c
SERVER_B_SRC = server_bonus.c

CLIENT_OBJ = $(CLIENT_SRC:.c=.o)
CLIENT_B_OBJ = $(CLIENT_B_SRC:.c=.o)

SERVER_OBJ = $(SERVER_SRC:.c=.o)
SERVER_B_OBJ = $(SERVER_B_SRC:.c=.o)

all: client server client_bonus server_bonus

$(NAME):
		$(CC) $(FLAGS) $(SERVER_SRC) $(TOOLS) -o $(NAME)

$(CLIENT):
		$(CC) $(FLAGS) $(CLIENT_SRC) $(TOOLS) -o $(CLIENT)

bonus: client_bonus server_bonus

$(NAME_B):
	$(CC) $(FLAGS) $(SERVER_B_SRC) $(TOOLS) -o $(NAME_B)
$(CLIENT_B):
	$(CC) $(FLAGS) $(CLIENT_B_SRC) $(TOOLS) -o $(CLIENT_B)

clean:
	$(RM) $(SERVER_OBJ) $(CLIENT_OBJ) $(SERVER_BONUS_OBJ) $(CLIENT_BONUS_OBJ)

fclean: clean
	$(RM) server client server_bonus client_bonus

re: fclean all

.PHONY: clean fclean re all bonus