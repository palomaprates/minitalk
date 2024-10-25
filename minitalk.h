#ifndef MINITALK_H
# define MINITALK_H

// #include "../ft_printf/ft_printf.h"
#include <stdio.h>
#include <unistd.h>
#include <signal.h>
#include <stdlib.h>

int	ft_strlen(const char *str);

int	str_to_int(char *str);

void	handle_signal(int signal);

#endif