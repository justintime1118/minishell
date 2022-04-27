/*

isatty

#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>

void	censor(int fd, const char *s)
{
	if (isatty(fd))
	{
		if (s)
			printf("%s is referring to a terminal\n", s);
		else
			printf("File Descriptor %d is referring to a terminal\n", fd);
	}
	else
	{
		if (s)
			printf("%s is not referring to a terminal\n", s);
		else
			printf("File Descriptor %d is not referring to a terminal\n", fd);
	}
}

int	main(void)
{
	int	fd;

	fd = open("./test", O_RDONLY);
	if (fd < 0)
		return (1);
	censor(STDIN_FILENO, "STDIN");
	censor(STDOUT_FILENO, "STDOUT");
	censor(STDERR_FILENO, "STDERR");
	censor(fd, NULL);
	censor(42, NULL);
	close(fd);
	return (0);
}
*/

/*

getenv

#include <stdlib.h>
#include <stdio.h>

int	main(void)
{
	char	*term;

	term = getenv("TERM");
	if (!term)
		return (1);
	printf("Term Type is %s\n", term);
	return (0);
}
*/

// signal -> 이건 더 공부해서 확실히 이해하자
#include <signal.h>
#include <stdbool.h>
#include <unistd.h>

void	handler(int signum)
{
	(void)signum;
	write(STDOUT_FILENO, "write From Signal\n", 18);
}

int	main(void)
{
	signal(SIGINT, handler);
	while(true)
		;
	return (0);
}