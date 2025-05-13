/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pprates- <pprates-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/13 10:59:20 by pprates-          #+#    #+#             */
/*   Updated: 2025/05/13 10:59:21 by pprates-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minitalk.h"

void	*ft_memset(void *s, int c, int n)
{
	int				i;
	int				temp_c;
	unsigned char	*temp_s;

	i = 0;
	temp_s = s;
	temp_c = c;
	while (i < n)
	{
		temp_s[i] = temp_c;
		i++;
	}
	temp_s[i] = '\0';
	return (s);
}
