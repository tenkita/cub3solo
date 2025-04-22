/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaisobe <kaisobe@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/27 17:27:18 by tkitago           #+#    #+#             */
/*   Updated: 2025/02/08 12:55:51 by kaisobe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	size_t	byte;
	void	*mem;

	if (!nmemb || !size)
	{
		return (xmalloc(0));
	}
	if (nmemb > SIZE_MAX / size)
	{
		return (NULL);
	}
	byte = nmemb * size;
	mem = xmalloc(byte);
	if (mem == NULL)
		return (NULL);
	ft_bzero(mem, byte);
	return (mem);
}
