/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_llstappend.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaisobe <kaisobe@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 12:58:06 by tkitago           #+#    #+#             */
/*   Updated: 2025/02/08 12:56:12 by kaisobe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_llstappend(void *lst_ptr, size_t size, void *new)
{
	void	*node;
	void	*tmp;

	node = xmalloc(size + sizeof(void *));
	if (!node)
		return (-1);
	ft_memcpy(node, new, size);
	*(void **)(node + size) = NULL;
	tmp = lst_ptr;
	while (*(void **)tmp)
		tmp = *(void **)tmp + size;
	*(void **)tmp = node;
	return (0);
}
// add node to custom link lst
// *lst_ptr point of point of to head node of lst
// mem size of alloc is sum of data size and ptr size of next node
// set NULL to mem posi which indicate next node ptr
// it means no next node
// set ptr of new node to next ptr of end node