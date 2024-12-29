# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mayilmaz <mayilmaz@student.42kocaeli.co    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/12/23 11:50:45 by mayilmaz          #+#    #+#              #
#    Updated: 2024/12/23 15:24:31 by mayilmaz         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SERVER = server
CLIENT = client

SRC_SER = server.c
SRC_CLI = client.c

CC = cc
CFLAGS = -Wall -Wextra -Werror

all: $(SERVER) $(CLIENT)

$(SERVER): $(SRC_SER)
	$(CC) $(CFLAGS) $(SRC_SER) -o $(SERVER)

$(CLIENT): $(SRC_CLI)
	$(CC) $(CFLAGS) $(SRC_CLI) -o $(CLIENT)

clean:
	rm -rf $(SERVER) $(CLIENT)

fclean: clean

re: fclean all

.PHONY: all clean fclean re