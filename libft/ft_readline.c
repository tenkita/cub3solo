/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_readline.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkitago <tkitago@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 12:55:59 by tkitago           #+#    #+#             */
/*   Updated: 2025/01/24 18:47:37 by tkitago          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_readline(t_bufferio *io)
{
	size_t	len;

	len = 0;
	while (1)
	{
		ft_strgeninteg(io->strgen);
		if (io->strgen->str)
		{
			while (!ft_strchr("\n", io->strgen->str[len]))
				len++;
			if (io->strgen->str[len] == '\n')
				return (ft_strgenfetch(io->strgen, ++len));
		}
		if (ft_bufferioread(io))
		{
			if (!io->strgen->str)
				return (NULL);
			return (ft_strgencomp(io->strgen));
		}
	}
}
// read data still /n or EOF
// add data in buf to main char line and able to search
// if /n found, get char line till that posi and return
// additional data read
// chechk buf unprocessed data (if end of file without /n)
