/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bufferioread.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkitago <tkitago@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 12:55:06 by tkitago           #+#    #+#             */
/*   Updated: 2025/01/24 18:47:28 by tkitago          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_bufferioread(t_bufferio *io)
{
	ssize_t	read_size;

	if (io->strgen->error)
		return (-1);
	read_size = read(io->fd, &io->strgen->buff[io->strgen->position],
			STRGEN_BUFFSIZE - io->strgen->position);
	if (read_size < 0)
		return (-1);
	io->strgen->position += read_size;
	if (io->strgen->position > STRGEN_BUFFSIZE)
		ft_strgeninteg(io->strgen);
	return (!read_size);
}
// read from fd associated with buf and accum to buf of strgen
// add read_size to current buf posi
// return 1 if read_size is 0(EOF)