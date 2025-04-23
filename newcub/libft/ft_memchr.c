/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkitago <tkitago@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/27 18:18:59 by tkitago           #+#    #+#             */
/*   Updated: 2024/11/01 16:57:00 by tkitago          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*str;

	str = (unsigned char *)s;
	while (n > 0)
	{
		if (*str == (unsigned char)c)
			return ((void *)str);
		str++;
		n--;
	}
	return (NULL);
}
// void	*ft_memchr(const void *s, int c, size_t n)
// {
// 	unsigned char	*str;
// 	size_t			i;

// 	i = 0;
// 	str = (unsigned char *)s;
// 	while (i < n)
// 	{
// 		if (str[i] == (unsigned char)c)
// 			return ((void *)(s + i));
// 		i++;
// 	}
// 	return (NULL);
// }

// It searches only the specified number of bytes n and returns a
// pointer to the first occurrence of the specified byte value c.
// Therefore, if n = 0,
// it means the search range is zero,so memchr performs
// no search and immediately returns NULL.