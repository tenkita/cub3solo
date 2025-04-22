/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_islong.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkitago <tkitago@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/15 08:00:17 by tkitago           #+#    #+#             */
/*   Updated: 2025/02/15 08:48:47 by tkitago          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	skip_space_and_sign(const char *nptr, int *i)
{
	while (ft_isspace(nptr[*i]))
		(*i)++;
	if (ft_issign(nptr[*i]))
	{
		if (nptr[(*i)++] == '-')
			return (-1);
	}
	return (1);
}

static int	parse_digits(const char *nptr, int *idx, int sign, long long *res)
{
	int	digit;

	while (nptr[*idx])
	{
		if (!ft_isdigit(nptr[*idx]))
			return (0);
		digit = nptr[(*idx)++] - '0';
		if (sign > 0)
		{
			if (*res > (LONG_MAX - digit) / 10)
				return (0);
			*res = *res * 10 + digit;
		}
		else
		{
			if (*res < (LONG_MIN + digit) / 10)
				return (0);
			*res = *res * 10 - digit;
		}
	}
	return (1);
}

int	ft_islong(const char *nptr)
{
	int			i;
	int			sign;
	long long	res;

	i = 0;
	res = 0;
	sign = skip_space_and_sign(nptr, &i);
	if (!ft_isdigit(nptr[i]))
		return (0);
	if (!parse_digits(nptr, &i, sign, &res))
		return (0);
	return (1);
}
