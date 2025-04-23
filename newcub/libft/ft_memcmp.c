/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkitago <tkitago@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/27 18:19:14 by tkitago           #+#    #+#             */
/*   Updated: 2024/11/22 18:16:51 by tkitago          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char	*str1;
	unsigned char	*str2;

	str1 = (unsigned char *)s1;
	str2 = (unsigned char *)s2;
	while (n--)
	{
		if (*str1 != *str2)
			return (*str1 - *str2);
		str1++;
		str2++;
	}
	return (0);
}

// int	ft_memcmp(const void *s1, const void *s2, size_t n)
// {
// 	size_t	i;

// 	i = 0;
// 	while (i < n)
// 	{
// 		if (*(unsigned char *)(s1 + i) != *(unsigned char *)(s2 + i))
// 			return (*(unsigned char *)(s1 + i) - *(unsigned char *)(s2 + i));
// 		i++;
// 	}
// 	return (0);
// }

// memcmp, on the other hand, is a function that compares whether
// the first n bytes of two memory areas are equal. When n=0,
// it considers them already equal since it is comparing zero bytes,
// so memcmp immediately returns 0 (indicating equality).