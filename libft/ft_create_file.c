/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_create_file.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaisobe <kaisobe@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/04 07:37:32 by kaisobe           #+#    #+#             */
/*   Updated: 2025/01/04 07:37:44 by kaisobe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_create_file(char *filename)
{
	return (open(filename, O_CREAT, S_IRGRP | S_IROTH | S_IWUSR | S_IRUSR));
}
