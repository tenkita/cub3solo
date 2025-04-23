/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hex.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaisobe <kaisobe@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 13:00:50 by tkitago           #+#    #+#             */
/*   Updated: 2025/02/14 08:06:25 by kaisobe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_hex(int fd, unsigned int i, int f)
{
	char	*hex;
	int		n;

	hex = ft_pointer_base((unsigned long long)i, 16);
	if (f == 1)
		hex = ft_tolower_all(hex);
	n = ft_str_count(fd, hex);
	free(hex);
	return (n);
}
