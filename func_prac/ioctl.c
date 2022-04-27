#include <stdio.h>
#include <sys/ioctl.h>
#include <unistd.h>

int	main(void)
{
	struct winsize	size;

	if (ioctl(STDIN_FILENO, TIOCGWINSZ, &size) == -1)
		return (1);
	printf("Terminal Row Size:\t%d\n",size.ws_row);
	printf("Terminal Col Size:\t%d\n",size.ws_col);
	return (0);
}