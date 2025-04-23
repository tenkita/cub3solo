/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_uint.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaisobe <kaisobe@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 13:01:31 by tkitago           #+#    #+#             */
/*   Updated: 2025/02/14 08:02:17 by kaisobe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_uint(int fd, unsigned int uint)
{
	char	str;
	int		digit;

	digit = 1;
	if (uint > 9)
		digit += ft_uint(fd, uint / 10);
	str = (uint % 10) + '0';
	write(fd, &str, 1);
	return (digit);
}
