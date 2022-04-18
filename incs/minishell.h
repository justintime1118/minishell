#ifndef MINISHELL_H
# define MINISHELL_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

# define SUCCESS	0
# define FAIL		1

// builtin
char	ft_exit(char **cmd);
char	ft_pwd(void);


#endif