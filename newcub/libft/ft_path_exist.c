/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_path_exist.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaisobe <kaisobe@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/03 13:57:26 by kaisobe           #+#    #+#             */
/*   Updated: 2025/01/04 07:49:15 by kaisobe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_path_exist(char *path)
{
	int	res;

	res = access(path, F_OK);
	if (res == 0)
		return (1);
	else
		return (0);
}
