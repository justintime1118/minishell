CC		= gcc
# CFLAG	= -Wextra -Werror -Wall
RM		= rm -f

NAME	= minishell
HEADER	= -I incs/
#HEADER	= -I incs/ -I utils/

SRCS	=	src/command.c \
			src/engine.c \
			src/main.c \
			src/parse.c \
			src/tune_fd.c \
			src/arraylist.c \
			src/builtin/cd.c \
			src/builtin/echo.c \
			src/builtin/env.c \
			src/builtin/exit.c \
			src/builtin/export.c \
			src/builtin/pwd.c \
			src/builtin/unset.c \



OBJS	=	$(SRCS:.c=.o) \
#			./utils/*.o

all : $(NAME)

$(NAME) : $(OBJS)
	$(CC) $(CFLAG) $(HEADER) -o $@ $^ -lreadline  -L ./utils -lft

%.o : %.c
#	$(MAKE) -C ./utils bonus
	$(CC) $(CFLAGS) $(HEADER) -c $< -o $@

clean :
#	$(MAKE) -C ./utils clean
	$(RM) $(OBJS)

fclean : clean
#	$(MAKE) -C ./utils fclean
	$(RM) $(NAME)

re : fclean all

.PHONY: all clean fclean re