/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkitago <tkitago@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/27 18:19:26 by tkitago           #+#    #+#             */
/*   Updated: 2024/11/22 18:17:07 by tkitago          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *s, int c, size_t n)
{
	unsigned char	*p;

	p = s;
	while (n--)
	{
		*p++ = (unsigned char)c;
	}
	return (s);
}

// void	*ft_memset(void *s, int c, size_t n)
// {
// 	size_t	i;

// 	i = 0;
// 	while (i < n)
// 	{
// 		*(unsigned char *)(s + i) = (unsigned char)c;
// 		i++;
// 	}
// 	return (s);
// }

//指定されたメモリ領域を特定の値で埋める