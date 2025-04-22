/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isint.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkitago <tkitago@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/25 14:06:45 by kaisobe           #+#    #+#             */
/*   Updated: 2025/02/03 08:41:56 by tkitago          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isint(const char *nptr)
{
	int			i;
	int			sign;
	long long	res;

	i = 0;
	sign = 1;
	res = 0;
	while (ft_isspace(nptr[i]))
		i++;
	if (ft_issign(nptr[i]))
		if (nptr[i++] == '-')
			sign *= -1;
	if (!ft_isdigit(nptr[i]))
		return (0);
	while (nptr[i])
	{
		if (!ft_isdigit(nptr[i]))
			return (0);
		res = res * 10 + sign * (nptr[i++] - '0');
		if (res > INT_MAX || res < INT_MIN)
			return (0);
	}
	return (1);
}
