/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkitago <tkitago@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/27 18:20:19 by tkitago           #+#    #+#             */
/*   Updated: 2025/02/08 17:19:26 by tkitago          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	cmp_char(char c1, char c2)
{
	if ((unsigned char)c1 != (unsigned char)c2)
		return ((unsigned char)c1 - (unsigned char)c2);
	return (0);
}

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	if (ft_strlen(s1) < n || ft_strlen(s2) < n)
		return (1);
	if (!*s1 || !*s2)
		return (1);
	while (*s1 && *s2 && n > 0)
	{
		if (cmp_char(*s1, *s2))
			return (*s1 - *s2);
		s1++;
		s2++;
		n--;
	}
	if (n > 0)
		return (cmp_char(*s1, *s2));
	return (0);
}

// int	ft_strncmp(const char *s1, const char *s2, size_t n)
// {
// 	size_t	i;

// 	i = 0;
// 	while (s1[i] != '\0' && s2[i] != '\0' && i < n)
// 	{
// 		if (cmp_char(s1[i], s2[i]))
// 			return (s1[i] - s2[i]);
// 		i++;
// 	}
// 	if (i < n)
// 		return (cmp_char(s1[i], s2[i]));
// 	return (0);
// }
