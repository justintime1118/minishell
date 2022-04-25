# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jiyoo <jiyoo@student.42seoul.kr>           +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/04/24 22:58:40 by jiyoo             #+#    #+#              #
#    Updated: 2022/04/24 23:11:02 by jiyoo            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc
CFLAGS = -Wall -Wextra -Werror
HEADER = ./incs/minishell.h
NAME = minishell

SRCS = \
./src/j_builtins.c \

all: $(NAME)

$(NAME):
	$(CC) $(CFLAGS) -I $(HEADER) ./src/j_builtins.c ./utils/*.c ./utils/libft/*.c -o $(NAME)


# all: $(NAME)

# OBJS = $(SRCS:.c=.o)

# $(NAME): $(OBJS)
# 	$(CC) $(CFLAGS) -I $(HEADER) $(OBJS) -o $(NAME)

# %.o: %.c $(HEADER)
# 	$(CC) $(CFLAGS) -I $(HEADER) -c $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re