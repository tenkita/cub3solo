/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaisobe <kaisobe@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/27 18:20:49 by tkitago           #+#    #+#             */
/*   Updated: 2025/02/12 09:43:42 by kaisobe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	i;
	size_t	j;
	char	*str;

	str = NULL;
	if (!((ft_strlen(s1) > 0) && (ft_strlen(set) > 0)))
	{
		return (ft_strdup(s1));
	}
	if (s1 != NULL && set != NULL)
	{
		i = 0;
		j = ft_strlen(s1);
		while (s1[i] && ft_strchr(set, s1[i]))
			i++;
		while (s1[j - 1] && ft_strchr(set, s1[j - 1]) && j > i)
			j--;
		str = (char *)xmalloc(sizeof(char) * (j - i + 1));
		if (!str)
			return (NULL);
		if (str)
			ft_strlcpy(str, &s1[i], j - i + 1);
	}
	return (str);
}
//文字列 1の先頭と末尾から、指定された文字集合setに含まれる文字を削除して、新しい文字列を返す