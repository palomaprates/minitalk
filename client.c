/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pprates- <pprates-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/13 10:58:58 by pprates-          #+#    #+#             */
/*   Updated: 2025/05/13 10:58:59 by pprates-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	to_send_len(char *str, char *server_pid)
{
	int	bit;
	int	len;
	int	bits_int;

	len = 0;
	bits_int = 31;
	while (str[len])
		len++;
	while (bits_int >= 0)
	{
		bit = (len >> bits_int) & 1;
		if (bit == 0)
			kill(ft_atoi(server_pid), SIGUSR1);
		else
			kill(ft_atoi(server_pid), SIGUSR2);
		bits_int--;
		usleep(100);
	}
}

void	to_send_ch(char *str, char *server_pid)
{
	int	bit;
	int	i;
	int	j;

	j = 0;
	while (str[j])
	{
		i = 7;
		while (i >= 0)
		{
			bit = (str[j] >> i) & 1;
			if (bit == 0)
				kill(atoi(server_pid), SIGUSR1);
			else
				kill(atoi(server_pid), SIGUSR2);
			i--;
			usleep(100);
		}
		j++;
	}
}

int	main(int argc, char *argv[])
{
	char	*server_pid;
	char	*str;

	if (argc == 3)
	{
		server_pid = argv[1];
		str = argv[2];
		to_send_len(str, server_pid);
		to_send_ch(str, server_pid);
	}
}
