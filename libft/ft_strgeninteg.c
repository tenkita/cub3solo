/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strgeninteg.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkitago <tkitago@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 12:56:42 by tkitago           #+#    #+#             */
/*   Updated: 2025/01/24 18:49:39 by tkitago          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_strgeninteg(t_strgen *strgen)
{
	char	*tmp;

	if (!strgen->position || strgen->error)
		return ;
	strgen->buff[strgen->position] = '\0';
	tmp = ft_strjoin2(strgen->str, strgen->buff);
	if (!tmp)
	{
		strgen->error = 1;
		return ;
	}
	free(strgen->str);
	strgen->str = tmp;
	strgen->position = 0;
}
// if no data in buf, ret
// insert \0 to buf and make if char line
// integrate data acuumlated to buf of strgen to str