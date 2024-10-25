#include <signal.h>
#include <stdlib.h>
#include <unistd.h>

int	main(int argc, char *argv[])
{
	if (argc == 3)
	{
		int	i;
		int	bit;
		char	*server_pid;
		char	ch; 
		server_pid = argv[1];
		ch = argv[2][0];
		i = 7;
		while (i >= 0) 
		{
			bit = (ch >> i) & 1;
			if (bit == 0)
			{
				kill(atoi(server_pid), SIGUSR1);
			}
			else
			{
				kill(atoi(server_pid), SIGUSR2);
			}
			i--;
			usleep(100);
		}
	}
}
