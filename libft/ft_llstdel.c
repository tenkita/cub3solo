/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_xlstdel.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkitago <tkitago@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 12:58:40 by tkitago           #+#    #+#             */
/*   Updated: 2025/01/26 16:41:43 by tkitago          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_llstdel(void *lst_ptr, size_t size, int index, void *dst)
{
	void	*node;
	void	*temp;

	if (index < 0)
	{
		index += ft_llstlen(*(void **)lst_ptr, size);
		if (index < 0)
			return (-1);
	}
	temp = lst_ptr;
	while (*(void **)temp && index--)
		temp = *(void **)temp + size;
	node = *(void **)temp;
	if (!node)
		return (-1);
	*(void **)temp = *(void **)(node + size);
	if (dst)
		ft_memcpy(dst, node, size);
	free(node);
	return (0);
}
// delete node on speci index from custom link lst and get the data
// index:index of delete node
// *dst: ptr to buf to store data of deleted node
// if index is nega, get lst len and add to be positive
// find node positioned designated index
// node indicate delete target
// set ptr of next node of target node to next ptr of tmp(current node)
// in pipex, dst is fixed to NULL(as arg), so no cpy data of deleted node