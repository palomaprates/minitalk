#ifndef MINITALK_H
# define MINITALK_H

#include <stdio.h>
#include <unistd.h>
#include <signal.h>
#include <stdlib.h>

int	ft_strlen(const char *str);

char	binary_to_char(char *str);

int	binary_to_int(char *str);

int	ft_atoi(const char *str);

char	*ft_itoa(int n);

void	*ft_memset(void *s, int c, int n);

void	to_get_final_str(int signal, char **final_str, int *index);

void	to_get_len(int signal, int *len);

void	to_send_len(char *str, char *server_pid);

void	to_send_ch(char *str, char *server_pid);

void	handle_signal(int signal);

#endif