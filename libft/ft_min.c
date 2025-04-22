/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_min.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaisobe <kaisobe@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/09 07:11:29 by kaisobe           #+#    #+#             */
/*   Updated: 2024/12/22 14:28:27 by kaisobe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_min(int argn, ...)
{
	va_list	ap;
	int		minimum;
	int		tmp;
	int		i;

	i = 0;
	va_start(ap, argn);
	minimum = INT_MAX;
	while (i < argn)
	{
		tmp = va_arg(ap, int);
		if (tmp < minimum)
		{
			minimum = tmp;
		}
		i++;
	}
	va_end(ap);
	return (minimum);
}
