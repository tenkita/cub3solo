/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim_safe.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaisobe <kaisobe@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/08 20:25:35 by kaisobe           #+#    #+#             */
/*   Updated: 2025/02/12 08:55:17 by kaisobe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim_safe(char *s1, char *set)
{
	char	*str;

	if (!s1)
		return (NULL);
	str = ft_strtrim(s1, set);
	free(s1);
	return (str);
}
