#include "minitalk.h"
	
void	handle_signal(int signal)
{
	static int	len = -1;
	static char *final_str = NULL;
	static int	index = -1;
	if (len == -1)
		to_get_len(signal, &len);
	else
{
		if (index == -1){
			final_str = malloc(sizeof(char) * len + 1);
			index++;
		to_get_final_str(signal, &final_str, &index);
			return;
		}
		to_get_final_str(signal, &final_str, &index);
		if (index == len){
			write(1, final_str, len);
			write(1, "\n", 1);
			free(final_str);
			final_str = NULL;
			index = -1;
			len = -1;
			}
}
}

int main()
{
	pid_t server_pid = getpid();
	write(1, ft_itoa(server_pid), ft_strlen(ft_itoa(server_pid)));
	write(1, "\n", 1);
	signal(SIGUSR1, handle_signal);
	signal(SIGUSR2, handle_signal);
	while(1)
	{
		pause();
	}
}