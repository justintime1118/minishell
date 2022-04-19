#include "minishell.h"

int	main(int argc, char **argv, char **env)
{
	ft_pwd();
	char **tmp = parse();
	int i = 0;
	while (tmp[i])
	{
		printf("%s\n", tmp[i]);
		i++;
	}
	return (0);
}