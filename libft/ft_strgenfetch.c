/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strgenfetch.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkitago <tkitago@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 12:56:35 by tkitago           #+#    #+#             */
/*   Updated: 2025/01/24 18:08:59 by tkitago          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strgenfetch(t_strgen *strgen, size_t len)
{
	char	*ret;
	char	*tmp;

	if (strgen->error)
		return (NULL);
	if (!len || !strgen->str)
		return (ft_strdup(""));
	tmp = ft_substr(strgen->str, len, -1);
	if (!tmp)
		return (NULL);
	ret = ft_substr(strgen->str, 0, len);
	if (!ret)
		free(tmp);
	else
	{
		if (!ft_strlen(tmp))
		{
			free(tmp);
			tmp = NULL;
		}
		free(strgen->str);
		strgen->str = tmp;
	}
	return (ret);
}
// get 0 to len num char from str and keep rest