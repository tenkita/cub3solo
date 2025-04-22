/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_chr_to_str.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaisobe <kaisobe@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/09 11:40:17 by kaisobe           #+#    #+#             */
/*   Updated: 2024/12/22 16:27:58 by kaisobe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_chr_to_str(char c)
{
	char	*out;

	out = (char *)ft_calloc(2, sizeof(char));
	if (out == NULL)
		return (NULL);
	out[0] = c;
	return (out);
}
