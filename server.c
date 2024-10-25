#include "minitalk.h"
#include <math.h>
#include "ft_itoa.c"
#include "ft_memset.c"
int	ft_strlen(const char *str)
{
	int	i;
	i = 0;
	while (str[i])
		i++;
	return (i);
}
char	binary_to_char(char *str)
{
	int	i;
	int	dec;
	int len;
	i = 0;
	dec = 0;
	len = ft_strlen(str);
	if (len == 8)
	{
		while (i < 8)
		{
			if (str[i] == '1')
				dec = (dec << 1) | (str[i] - '0');
			i++;
		}
	}
	return ((char)dec);
}
void	handle_signal(int signal)
{
	static int	i = 0;
	static char	bin[9] = {0};
	char c;
	if (signal == SIGUSR1)
		bin[i] = '0';
	if (signal == SIGUSR2)
		bin[i] = '1';
	i++;
		c = binary_to_char(bin);
		write(1, &c, 1);
		i = 0;
		ft_memset(bin, 0, 9);
}

int main()
{
	pid_t server_pid = getpid();
	printf("%d\n", server_pid); //lembrar que nao posso usar o printf
	signal(SIGUSR1, handle_signal);
	signal(SIGUSR2, handle_signal);
	while(1)
	{
	}
}
