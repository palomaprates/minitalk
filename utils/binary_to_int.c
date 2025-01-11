#include "../minitalk.h"

int binary_to_int(char *str)
{
	int i;
	int	dec;
	
	i = 0; 
	dec = 0;
	while (i < 32)
	{
		dec = (dec << 1) | (str[i] - '0'); 
		i++;
	}
	return (dec);
}
