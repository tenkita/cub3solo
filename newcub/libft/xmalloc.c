/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   xmalloc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaisobe <kaisobe@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/08 12:53:35 by kaisobe           #+#    #+#             */
/*   Updated: 2025/02/08 12:55:14 by kaisobe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*xmalloc(size_t size)
{
	void	*newmem;

	newmem = malloc(size);
	if (!newmem)
	{
		perror("malloc");
		exit(EXIT_FAILURE);
	}
	return (newmem);
}
