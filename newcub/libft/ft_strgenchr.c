/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strgenchr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkitago <tkitago@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 12:56:13 by tkitago           #+#    #+#             */
/*   Updated: 2025/01/24 18:47:13 by tkitago          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_strgenchr(t_strgen *strgen, char insert_char)
{
	if (strgen->error)
		return ;
	strgen->buff[strgen->position++] = insert_char;
	if (strgen->position >= STRGEN_BUFFSIZE)
		ft_strgeninteg(strgen);
}
// add a char to strgen
// if buf is full, connect with main charline