#include "get_next_line.h"
#include <stdio.h>
#include <fcntl.h>
int	main()
{
	int fd = open("DELETEME.txt", O_RDONLY);
	printf("1) %s\n", get_next_line(fd));
	// printf("2) %s\n", get_next_line(fd));
	// printf("3) %s\n", get_next_line(fd));
}
