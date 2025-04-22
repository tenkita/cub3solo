/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pointer.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaisobe <kaisobe@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 13:01:07 by tkitago           #+#    #+#             */
/*   Updated: 2025/02/14 08:07:09 by kaisobe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_pointer(int fd, unsigned long long pointer)
{
	char	*point_ad;
	int		num;

	if (pointer == 0)
		return (write(fd, "(nil)", ft_strlen("(nil)")));
	point_ad = ft_tolower_all(ft_pointer_base(pointer, 16));
	num = ft_str_count(fd, "0x");
	num += ft_str_count(fd, point_ad);
	free(point_ad);
	return (num);
}
