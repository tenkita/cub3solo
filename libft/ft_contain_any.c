/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_contain_any.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaisobe <kaisobe@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 16:17:35 by kaisobe           #+#    #+#             */
/*   Updated: 2025/02/13 16:17:36 by kaisobe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_contain_any(const char *str, const char *set)
{
	size_t	i;

	i = 0;
	while (i < ft_strlen(str))
	{
		if (ft_contain(set, str[i]))
		{
			return (1);
		}
		i++;
	}
	return (0);
}
