#include "../minitalk.h"

int	ft_atoi(const char *str)
{
	int	i;
	int	nbr;
	int	negative_sign;

	i = 0;
	nbr = 0;
	negative_sign = 1;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == 32)
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			negative_sign *= -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		nbr = nbr * 10 + str[i] - 48;
		i++;
	}
	return (nbr * negative_sign);
}
