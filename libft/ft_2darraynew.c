/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_2darraynew.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaisobe <kaisobe@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/12 18:22:10 by tkitago           #+#    #+#             */
/*   Updated: 2025/02/08 12:55:38 by kaisobe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	clean(char **array, size_t i)
{
	while (i--)
		free(array[i]);
	free(array);
}

void	*ft_2darraynew(size_t size, size_t width, size_t height)
{
	char	**array;
	size_t	n[2];
	size_t	i;

	n[0] = sizeof(void *) * (width + 1);
	n[1] = size * height;
	if (n[0] / sizeof(void *) != (width + 1) || n[1] / size != height)
		return (NULL);
	array = xmalloc(n[0]);
	if (!array)
		return (NULL);
	i = 0;
	while (i < width)
	{
		array[i] = xmalloc(n[1]);
		if (!array[i++])
		{
			clean(array, --i);
			return (NULL);
		}
	}
	array[i] = NULL;
	return (array);
}
