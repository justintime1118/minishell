CC		= gcc
# CFLAG	= -Wextra -Werror -Wall
RM		= rm -f

NAME	= minishell
HEADER	= -I incs/ -I utils/

SRCS	=	src/command.c \
			src/engine.c \
			src/main.c \
			src/parse.c \
			src/tune_fd.c \
			src/arraylist.c \
			src/builtin/*.c


OBJS	=	$(SRCS:.c=.o) \
			./utils/*.o

all : $(NAME)

$(NAME) : $(OBJS)
	$(CC) $(CFLAG) $(HEADER) -o $@ $^ -lreadline

%.o : %.c
	$(MAKE) -C ./utils bonus
	$(CC) $(CFLAGS) $(HEADER) -c $< -o $@

clean :
	$(MAKE) -C ./utils clean
	$(RM) $(OBJS)

fclean : clean
	$(MAKE) -C ./utils fclean
	$(RM) $(NAME)

re : fclean all

.PHONY: all clean fclean re