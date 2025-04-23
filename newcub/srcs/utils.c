/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkitago <tkitago@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/23 13:02:31 by tkitago           #+#    #+#             */
/*   Updated: 2025/04/23 20:19:10 by tkitago          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

char	**realloc_2d(char **old, int size, int new_capa)
{
	int		i;
	char	**new_arr;

	i = 0;
	new_arr = malloc(sizeof(char *) * new_capa);
    if (!new_arr)
    {
        free(old);
        return(NULL);
    }
	while (i < size)
	{
		new_arr[i] = old[i];
		i++;
	}
	free(old);
	return (new_arr);
}

int	put_error(const char *msg)
{
	ft_putendl_fd((char *)msg, 2);
	return (0);
}

void	free_2d(char **str)
{
	int i;

	if (!str)
		return ;
	i = 0;
	while (str[i])
	{
		free(str[i]);
		i++;
	}
	free(str);
}
