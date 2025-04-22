/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin_safe.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaisobe <kaisobe@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/04 18:35:19 by kaisobe           #+#    #+#             */
/*   Updated: 2025/02/08 12:56:49 by kaisobe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin_safe(char *s1, char *s2, int is_free1, int is_free2)
{
	char	*res;
	size_t	length;
	size_t	i;

	length = ft_strlen(s1) + ft_strlen(s2);
	res = (char *)xmalloc(sizeof(char) * (length + 1));
	if (res == NULL)
		return (NULL);
	i = 0;
	while (i < ft_strlen(s1))
	{
		res[i] = s1[i];
		i++;
	}
	while (i < length)
	{
		res[i] = s2[i - ft_strlen(s1)];
		i++;
	}
	res[i] = '\0';
	if (is_free1 && s1)
		free(s1);
	if (is_free2 && s2)
		free(s2);
	return (res);
}
