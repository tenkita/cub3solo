/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bufferionew.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaisobe <kaisobe@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 12:54:52 by tkitago           #+#    #+#             */
/*   Updated: 2025/02/08 12:55:45 by kaisobe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_bufferio	*ft_bufferionew(int fd, int close_on_error)
{
	t_bufferio	*ret;

	if (fd == -1)
		return (NULL);
	ret = (t_bufferio *)xmalloc(sizeof(t_bufferio));
	if (!ret)
	{
		if (close_on_error)
			close(fd);
		return (NULL);
	}
	ret->strgen = ft_strgeninit();
	if (!ret->strgen)
	{
		free(ret);
		if (close_on_error)
			close(fd);
		return (NULL);
	}
	ret->fd = fd;
	return (ret);
}
// init bufferio and set fd and resource