/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkitago <tkitago@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/27 18:20:04 by tkitago           #+#    #+#             */
/*   Updated: 2025/01/24 18:16:49 by tkitago          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t size)
{
	size_t	i;
	size_t	j;
	size_t	dest_len;
	size_t	src_len;

	src_len = ft_strlen(src);
	dest_len = ft_strlen(dest);
	j = dest_len;
	i = 0;
	if (dest_len < size - 1 && size > 0)
	{
		while (src[i] != '\0' && dest_len + i < size - 1)
		{
			dest[j] = src[i];
			j++;
			i++;
		}
		dest[j] = 0;
	}
	if (dest_len >= size)
		dest_len = size;
	return (dest_len + src_len);
}
//バッファサイズを考慮しながら、srcをdestに連結