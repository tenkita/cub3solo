/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strgencomp.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkitago <tkitago@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 12:56:20 by tkitago           #+#    #+#             */
/*   Updated: 2025/01/24 18:47:44 by tkitago          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strgencomp(t_strgen *strgen)
{
	char	*ret;

	ft_strgeninteg(strgen);
	if (!strgen->error)
	{
		ret = strgen->str;
		if (!ret)
		{
			ret = ft_strdup("");
			if (!ret)
				strgen->error = 1;
		}
	}
	if (strgen->error)
	{
		free(strgen->str);
		ret = NULL;
	}
	strgen->str = NULL;
	strgen->position = 0;
	strgen->error = 0;
	return (ret);
}
// integrate data of buf to main charline(str)
// if mis of init dup ""
// if error, free mem of str
// ret complite line