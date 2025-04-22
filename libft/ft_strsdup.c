/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsdup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaisobe <kaisobe@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/06 16:45:31 by kaisobe           #+#    #+#             */
/*   Updated: 2025/02/08 12:57:08 by kaisobe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	**ft_strsdup(char **strs)
{
	char	**out;
	size_t	len;
	size_t	i;

	len = ft_strslen((const char **)strs);
	out = (char **)xmalloc(sizeof(char *) * (len + 1));
	if (!out)
		return (NULL);
	i = 0;
	while (i < len)
	{
		out[i] = ft_strdup(strs[i]);
		if (!out[i])
			return (ft_2darraydel(out), NULL);
		i++;
	}
	out[i] = NULL;
	return (out);
}
