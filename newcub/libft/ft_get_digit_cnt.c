/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_digit_cnt.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaisobe <kaisobe@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 00:06:35 by kaisobe           #+#    #+#             */
/*   Updated: 2024/12/22 14:19:54 by kaisobe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_get_digit_cnt(uintptr_t n, unsigned int base)
{
	int	digit_cnt;

	digit_cnt = 1;
	while (n >= base)
	{
		digit_cnt++;
		n /= base;
	}
	return (digit_cnt);
}
