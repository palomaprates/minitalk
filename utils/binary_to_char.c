#include "../minitalk.h"

char	binary_to_char(char *str)
{
	int	i;
	int	dec;

	i = 0;
	dec = 0;
	while (i < 8)
	{
		dec = (dec << 1) | (str[i] - '0');
		i++;
	}
	return ((char)(dec));
}
