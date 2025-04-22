/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calc_next_str.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaisobe <kaisobe@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/09 11:41:54 by kaisobe           #+#    #+#             */
/*   Updated: 2025/01/03 14:02:43 by kaisobe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_calc_next_str(char *src, char *set)
{
	size_t	i;
	int		min_idx;

	i = 0;
	min_idx = ft_strlen(src);
	while (i < ft_strlen(set))
	{
		min_idx = ft_min(2, min_idx, ft_calc_next_chr(src, set[i]));
		i++;
	}
	return (min_idx);
}
