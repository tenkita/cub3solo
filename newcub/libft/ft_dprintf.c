/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dprintf.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaisobe <kaisobe@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 10:51:02 by tkitago           #+#    #+#             */
/*   Updated: 2025/02/14 08:08:01 by kaisobe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_dprintf(int fd, const char *input, ...)
{
	va_list	args;
	int		num;

	num = 0;
	if (!input)
		return (-1);
	va_start(args, input);
	num = ft_unfo_output(fd, input, args);
	va_end(args);
	return (num);
}
