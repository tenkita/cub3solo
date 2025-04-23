/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gnl.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkitago <tkitago@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/23 13:02:57 by tkitago           #+#    #+#             */
/*   Updated: 2025/04/23 15:53:34 by tkitago          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	ft_putc(t_string *str, char c)
{
	size_t	new_capa;
	char	*new_str;
	size_t	i;

	i = 0;
	if (str->len + 1 > str->capa)
	{
		if (str->capa == 0)
			new_capa = BUFF_SIZE;
		else
			new_capa = str->capa * 2;
		new_str = (char *)malloc(new_capa);
		if (!new_str)
			return (0);
		while (i < str->len)
		{
			new_str[i] = str->str[i];
			i++;
		}
		free(str->str);
		str->str = new_str;
		str->capa = new_capa;
	}
	str->str[str->len++] = c;
	return (1);
}

int	ft_getchar(int fd)
{
	static char	buf[BUFF_SIZE];
	static char	*bufp;
	static int	n = 0;

	if (n == 0)
	{
		n = read(fd, buf, sizeof(buf));
		if (n <= 0)
		{
			return (EOF);
		}
		bufp = buf;
	}
	if (--n >= 0)
		return ((unsigned char)*bufp++);
	else
		return (EOF);
}

int	free_gnl_str(t_string *str)
{
	free(str->str);
	return (0);
}

void	init_gnl(t_string *str)
{
	str->capa = 0;
	str->len = 0;
	str->str = NULL;
}

// 0 = NULL
int	get_next_line(int fd, char **line)
{
	t_string	ret;
	int			c;

	init_gnl(&ret);
	while (1)
	{
		c = ft_getchar(fd);
		if (c == EOF)
			break ;
		if (!ft_putc(&ret, c))
			return (free_gnl_str(&ret));
		if (c == '\n')
			break ;
	}
	if (ret.len > 0)
	{
		if (!ft_putc(&ret, '\0'))
			return (free_gnl_str(&ret));
		*line = ret.str;
		return (1);
	}
	free(ret.str);
	*line = NULL;
	return (0);
}
