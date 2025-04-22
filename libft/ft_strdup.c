/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkitago <tkitago@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/27 18:19:53 by tkitago           #+#    #+#             */
/*   Updated: 2025/02/08 17:16:16 by tkitago          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	char	*str;
	char	*dest;

	str = (char *)xmalloc(sizeof(char) * (ft_strlen(s) + 1));
	if (!str)
		return (NULL);
	dest = str;
	while (s && *s != '\0')
	{
		*dest++ = *s++;
	}
	*dest = '\0';
	return (str);
}

// char	*ft_strdup(const char *s)
// {
// 	char	*str;
// 	size_t	i;

// 	str = (char *)xmalloc(sizeof(char) * (ft_strlen(s) + 1));
// 	if (!str)
// 		return (NULL);
// 	i = 0;
// 	while (s[i] != '\0')
// 	{
// 		str[i] = s[i];
// 		i++;
// 	}
// 	str[i] = '\0';
// 	return (str);
// }
