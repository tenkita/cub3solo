/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_llst2array.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaisobe <kaisobe@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 12:57:57 by tkitago           #+#    #+#             */
/*   Updated: 2025/02/08 12:56:09 by kaisobe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_llst2array(void *lst, size_t size, size_t *node_num)
{
	size_t	len;
	void	*array;
	void	*head;

	len = ft_llstlen(lst, size);
	array = xmalloc(len * size);
	if (!array)
		return (NULL);
	head = array;
	while (lst)
	{
		ft_memcpy(array, lst, size);
		array += size;
		lst = *(void **)(lst + size);
	}
	if (node_num)
		*node_num = len;
	return (head);
}
// custom link lst is link lst corresponding to speci usage or demand
// *lst: point of top node of lst
// size: byte size of data in each node
// move point to next posi of array
// get point of next node from current node