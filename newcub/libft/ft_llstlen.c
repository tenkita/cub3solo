/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_xlstlen.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkitago <tkitago@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 12:58:28 by tkitago           #+#    #+#             */
/*   Updated: 2025/01/26 16:41:48 by tkitago          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_llstlen(void *lst, size_t size)
{
	size_t	count;

	count = 0;
	while (lst)
	{
		lst = *(void **)(lst + size);
		count++;
	}
	return (count);
}
// get head ptr of lst and offset(which exist ptr of next node)
// and return node num
// offset: how byte far typi mem in stuc from head of struc
// *lst: designate start point of lst
// size: where is ptr of next node in node struc
// cast address(lst + size) to void**(indicate ptr of next node)
// get actual ptr value(void *) from casted adrr