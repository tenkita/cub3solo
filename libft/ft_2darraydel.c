/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_2darraydel.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkitago <tkitago@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/12 18:26:21 by tkitago           #+#    #+#             */
/*   Updated: 2025/01/16 12:25:30 by tkitago          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_2darraydel(void *array)
{
	char	**ptr;

	ptr = array;
	while (*ptr)
		free(*ptr++);
	free(array);
}
