/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calc_back_chr.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaisobe <kaisobe@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 14:45:03 by kaisobe           #+#    #+#             */
/*   Updated: 2025/02/10 14:45:46 by kaisobe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_calc_back_chr(char *str, char c)
{
	char	*s;

	s = ft_strrchr(str, c);
	if (s == NULL)
	{
		return (-1);
	}
	return (s - str);
}
