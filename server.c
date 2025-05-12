#include "minitalk.h"

void	reset_str(char **final_str, int *index, int *len)
{
	free(*final_str);
	*final_str = NULL;
	*index = -1;
	*len = -1;
}

void	handle_signal(int signal)
{
	static int	len = -1;
	static char	*final_str = NULL;
	static int	index = -1;

	if (len == -1)
		to_get_len(signal, &len);
	else
	{
		if (index == -1)
		{
			final_str = malloc(sizeof(char) * len + 1);
			if (!final_str)
				exit(1);
			index++;
			return (to_get_final_str(signal, &final_str, &index));
		}
		to_get_final_str(signal, &final_str, &index);
		if (index == len)
		{
			write(1, final_str, len);
			write(1, "\n", 1);
			reset_str(&final_str, &index, &len);
		}
	}
}

int	main(void)
{
	pid_t	server_pid;
	char	*pid;

	server_pid = getpid();
	if (server_pid < 0)
		return (0);
	pid = ft_itoa(server_pid);
	write(1, pid, ft_strlen(pid));
	write(1, "\n", 1);
	free(pid);
	signal(SIGUSR1, handle_signal);
	signal(SIGUSR2, handle_signal);
	while (1)
	{
		pause();
	}
}
