/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ndarraydel.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkitago <tkitago@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 13:20:25 by tkitago           #+#    #+#             */
/*   Updated: 2025/01/24 19:02:51 by tkitago          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_ndarraydel(void *array, size_t ndim)
{
	void	*head;
	size_t	i;

	head = array;
	i = 0;
	if (1 < ndim)
		while (((void **)array)[i])
			ft_ndarraydel(((void **)array)[i++], ndim - 1);
	free(head);
}
