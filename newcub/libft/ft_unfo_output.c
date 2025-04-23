/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unfo_output.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaisobe <kaisobe@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 13:01:36 by tkitago           #+#    #+#             */
/*   Updated: 2025/02/14 08:04:22 by kaisobe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_unfo_output(int fd, const char *input, va_list args)
{
	size_t	i;
	size_t	c;

	i = 0;
	c = 0;
	while (input[i])
	{
		if (input[i] == '%' && input[i + 1])
		{
			i++;
			c += ft_format(fd, input[i], args);
		}
		else
		{
			ft_putchar_fd(input[i], fd);
			c++;
		}
		i++;
	}
	return (c);
}
// add num of words from 'ft_format' and return it(c)