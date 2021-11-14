#include "get_next_line.h"
#include <stdio.h>
#include <fcntl.h>
int	main()
{
	int fd = open("DELETEME.txt", O_RDONLY);
	printf("1) %s", get_next_line(fd));
	printf("2) %s", get_next_line(fd));
	printf("3) %s", get_next_line(fd));
	printf("4) %s", get_next_line(fd));
	printf("5) %s", get_next_line(fd));
	printf("6) %s", get_next_line(fd));
	close(fd);
	return (0);
}
