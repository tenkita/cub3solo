/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bufferiodel.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkitago <tkitago@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 12:54:32 by tkitago           #+#    #+#             */
/*   Updated: 2025/01/24 17:31:42 by tkitago          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bufferiodel(t_bufferio *io, int do_close)
{
	ft_strgendel(io->strgen);
	if (do_close)
		close(io->fd);
	free(io);
}
// free bufferio and close fd needed