#include "../minitalk.h"

void	to_get_len(int signal, int *len)
{
	static char	binary[32];
	static int	i = 0;

	binary[31] = '\0';
	if (i < 32)
	{
		if (signal == SIGUSR1)
			binary[i] = '0';
		else if (signal == SIGUSR2)
			binary[i] = '1';
		i++;
	}
	if (i == 32)
	{
		*len = binary_to_int(binary);
		i = 0;
	}
}
