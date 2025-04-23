/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_format.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaisobe <kaisobe@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 12:01:17 by tkitago           #+#    #+#             */
/*   Updated: 2025/02/14 08:03:18 by kaisobe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_format(int fd, int c, va_list args)
{
	int	n;

	n = 0;
	if (c == 'c')
		n = ft_char(fd, va_arg(args, int));
	else if (c == 's')
		n = ft_str(fd, va_arg(args, char *));
	else if (c == 'p')
		n = ft_pointer(fd, (unsigned long long)va_arg(args, void *));
	else if (c == 'd' || c == 'i')
		n = ft_int(fd, va_arg(args, int));
	else if (c == 'u')
		n = ft_uint(fd, va_arg(args, unsigned long long));
	else if (c == 'x')
		n = ft_hex(fd, va_arg(args, unsigned int), 1);
	else if (c == 'X')
		n = ft_hex(fd, va_arg(args, unsigned int), 2);
	else if (c == '%')
		n = ft_str_count(fd, "%");
	return (n);
}
// va_arg(args, xxx) can translate the type