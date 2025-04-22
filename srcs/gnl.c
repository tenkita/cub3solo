
#include "get_next_line.h"

int	ft_putc(t_string *str, char c)
{
	size_t	new_capa;
	char	*new_str;

	if (str->len + 1 > str->capa)
	{
		new_capa = (str->capa == 0) ? BUFF_SIZE : str->capa * 2;
		new_str = (char *)malloc(new_capa);
		if (!new_str)
		{
			return (0);
		}
		for (size_t i = 0; i < str->len; i++)
		{
			new_str[i] = str->str[i];
		}
		free(str->str);
		str->str = new_str;
		str->capa = new_capa;
	}
	str->str[str->len] = c;
	str->len++;
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
	return ((--n >= 0) ? (unsigned char)*bufp++ : EOF);
}
// 0 = NULL
int	get_next_line(int fd, char **line)
{
	t_string	ret;
	int			c;

	ret.str = NULL;
	ret.len = 0;
	ret.capa = 0;
	while (1)
	{
		c = ft_getchar(fd);
		if (c == EOF)
			break ;
		if (!ft_putc(&ret, c))
		{
			free(ret.str);
			return (0);
		}
		if (c == '\n')
			break ;
	}
	if (ret.len > 0)
	{
		if (!ft_putc(&ret, '\0'))
		{
			free(ret.str);
			return (0);
		}
		*line = ret.str;
		return (1);
	}
	free(ret.str);
	*line = NULL;
	return (0);
}

