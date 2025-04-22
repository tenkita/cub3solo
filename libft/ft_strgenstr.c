/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strgenstr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkitago <tkitago@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 12:57:14 by tkitago           #+#    #+#             */
/*   Updated: 2025/01/24 18:16:26 by tkitago          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_strgenstr(t_strgen *strgen, char *insert_char)
{
	while (!strgen->error && *insert_char)
		ft_strgenchr(strgen, *insert_char++);
}
// add each char to buf and integrate if needed