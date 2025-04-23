/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_max.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaisobe <kaisobe@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/09 07:01:44 by kaisobe           #+#    #+#             */
/*   Updated: 2024/12/22 14:28:23 by kaisobe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_max(int argn, ...)
{
	va_list	ap;
	int		maximum;
	int		tmp;
	int		i;

	i = 0;
	va_start(ap, argn);
	maximum = INT_MIN;
	while (i < argn)
	{
		tmp = va_arg(ap, int);
		if (tmp > maximum)
		{
			maximum = tmp;
		}
		i++;
	}
	va_end(ap);
	return (maximum);
}
