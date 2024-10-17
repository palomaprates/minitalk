#include <stdio.h>
#include <signal.h>
#include <stdlib.h>

int	main(int argc, char *argv[])
{
	int	i;
	i = 0;
		if (argc == 2)
		{
			char *server_pid = argv[1];
			kill(atoi(server_pid), SIGUSR1);
		}
}
