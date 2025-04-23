/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkitago <tkitago@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/27 18:18:21 by tkitago           #+#    #+#             */
/*   Updated: 2025/04/22 21:25:01 by tkitago          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	check_ovf(int neg_flag, long long num, char x)
{
	if (neg_flag == 1)
		if (num > ((LONG_MAX - (x - '0')) / 10) || (LONG_MAX / 10 == num
				&& LONG_MAX % 10 <= x - '0'))
			return (1);
	if (neg_flag == -1)
		if (-num < ((LONG_MIN + (x - '0')) / 10) || (((LONG_MIN + (x - '0'))
					/ 10) == -num && LONG_MIN % 10 >= -(x - '0')))
			return (-1);
	return (0);
}

const char	*skip_space_renegflag(const char *str, int *neg_flag)
{
	while ((*str >= 9 && *str <= 13) || *str == ' ')
		str++;
	*neg_flag = 1;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			*neg_flag = -1;
		str++;
	}
	return (str);
}

int	ft_atoi(const char *str)
{
	int			neg_flag;
	long long	res;
	int			i;

	str = skip_space_renegflag(str, &neg_flag);
	res = 0;
	i = 0;
	while (*str >= '0' && *str <= '9')
	{
		// if (*str >= '0' && *str <= '9')
		// 	return (-1);
		if (!ft_isdigit(*str))
			return (-1);
		if (check_ovf(neg_flag, res, *str) == 1)
			return ((int)LONG_MAX);
		if (check_ovf(neg_flag, res, *str) == -1)
			return ((int)LONG_MIN);
		res = res * 10 + (*str - '0');
		str++;
	}
	return ((int)res * neg_flag);
}

// #include <stdio.h>

// int	main(void)
// {
// 	int	result;

// 	const char *tests[] = {
// 		// "42",
// 		// "-42",
// 		// "2147483647",
// 		// "-2147483648",
// 		"9223372036854775807",  // LONG_MAX
// 		"-9223372036854775808", // LONG_MI
// 		"9223372036854775808",  // LONG_MAX + 1
// 		"-9223372036854775809", // LONG_MIN - 1
// 								// "   123abc456",
// 								// "00000123",
// 	};
// 	for (int i = 0; i < sizeof(tests) / sizeof(tests[0]); i++)
// 	{
// 		result = ft_atoi(tests[i]);
// 		printf("ft_atoi(\"%s\") = %d; \n", tests[i], result);
// 	}
// 	return (0);
// }
