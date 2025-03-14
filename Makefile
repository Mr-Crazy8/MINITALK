CC = cc
CFLAGS = -Wall -Wextra -Werror

MANDATORY_SRCS = client.c server.c helper_func.c ft_atoi.c
BONUS_SRCS = bonus/client_bonus.c bonus/server_bonus.c bonus/helper_func_bonus.c ft_atoi.c

MANDATORY_OBJS = $(MANDATORY_SRCS:.c=.o)
BONUS_OBJS = $(BONUS_SRCS:.c=.o)

MANDATORY_NAME = client server
BONUS_NAME = client_bonus server_bonus

all: $(MANDATORY_NAME)

client: client.o helper_func.o 
	$(CC) $(CFLAGS) client.o helper_func.o  -o client

server: server.o helper_func.o ft_atoi.o
	$(CC) $(CFLAGS) server.o helper_func.o ft_atoi.o -o server

bonus: $(BONUS_NAME)

client_bonus: bonus/client_bonus.o bonus/helper_func_bonus.o 
	$(CC) $(CFLAGS) bonus/client_bonus.o bonus/helper_func_bonus.o  -o client_bonus

server_bonus: bonus/server_bonus.o bonus/helper_func_bonus.o 
	$(CC) $(CFLAGS) bonus/server_bonus.o bonus/helper_func_bonus.o  -o server_bonus

%.o: %.c minitalk.h bonus/minitalk_bonus.h
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(MANDATORY_OBJS) $(BONUS_OBJS)

fclean: clean
	rm -f $(MANDATORY_NAME) $(BONUS_NAME)

re: fclean all

.PHONY: all bonus clean fclean re