CC		= gcc
# CFLAG	= -Wextra -Werror -Wall
RM		= rm -f

NAME	= minishell
HEAD	= incs/ -I utils/

SRCS	=	src/main.c \
			src/parse.c \
			src/engine.c \
			src/command.c \
			src/tune_fd.c \
			src/builtin/echo.c \
			src/builtin/exit.c \
			src/builtin/pwd.c \
			src/builtin/unset.c 


OBJS	=	$(SRCS:.c=.o) \
			./utils/*.o

all : $(NAME)

$(NAME) : $(OBJS)
	$(CC) $(CFLAG) -I $(HEAD)  -o $@ $^ -lreadline

%.o : %.c
	$(MAKE) -C ./utils bonus
	$(CC) $(CFLAGS) -I $(HEAD) -c $< -o $@

clean :
	$(MAKE) -C ./utils clean
	$(RM) $(OBJS)

fclean : clean
	$(MAKE) -C ./utils fclean
	$(RM) $(NAME)

re : fclean all

.PHONY: all clean fclean re