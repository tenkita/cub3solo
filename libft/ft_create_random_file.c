/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_create_random_file.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaisobe <kaisobe@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/04 07:38:02 by kaisobe           #+#    #+#             */
/*   Updated: 2025/02/08 11:07:14 by kaisobe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_create_random_file(char *prefix, char *extension)
{
	char		*out;
	char		*tmp;
	u_int32_t	rand;
	int			fd;

	rand = ft_rand_u32(ft_generate_seed());
	tmp = ft_utoa(rand);
	if (!tmp)
		return (NULL);
	out = ft_strjoin_safe(prefix, tmp, 0, 1);
	out = ft_strjoin_safe(out, extension, 1, 0);
	if (ft_path_exist(out))
	{
		free(out);
		return (ft_create_random_file(prefix, extension));
	}
	fd = ft_create_file(out);
	if (fd == -1)
		return (NULL);
	close(fd);
	return (out);
}
