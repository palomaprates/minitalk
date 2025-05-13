/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   to_get_final_str.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pprates- <pprates-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/13 10:59:07 by pprates-          #+#    #+#             */
/*   Updated: 2025/05/13 10:59:08 by pprates-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minitalk.h"

void	to_get_final_str(int signal, char **final_str, int *index)
{
	static char	str_binary[9];
	static int	i = 0;

	str_binary[8] = '\0';
	if (i < 8)
	{
		if (signal == SIGUSR1)
			str_binary[i] = '0';
		else
			str_binary[i] = '1';
		i++;
	}
	if (i == 8)
	{
		(*final_str)[*index] = binary_to_char(str_binary);
		*index = *index + 1;
		i = 0;
	}
}
