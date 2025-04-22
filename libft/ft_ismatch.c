/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ismatch.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaisobe <kaisobe@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/09 18:47:24 by kaisobe           #+#    #+#             */
/*   Updated: 2024/12/22 14:05:29 by kaisobe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_ismatch(int x, int argn, ...)
{
	va_list	ap;
	int		value;
	int		i;

	i = 0;
	va_start(ap, argn);
	while (i < argn)
	{
		value = va_arg(ap, int);
		if (x == value)
			return (1);
		i++;
	}
	va_end(ap);
	return (0);
}
