
#include "cub3d.h"

// テクスチャや色の識別子が含まれていれば mapじゃない
// mapに使われる文字が1つでも含まれていれば map行とする
// FとCは床の色の判定だから先に弾く
int	is_map_line(char *line)
{
	while (*line == ' ' || *line == '\t')
		line++;
	if (!line || !strncmp(line, "NO ", 3) || !strncmp(line, "SO ", 3)
		|| !strncmp(line, "WE ", 3) || !strncmp(line, "EA ", 3)
		|| line[0] == 'F' || line[0] == 'C')
		return (THIS_IS_NOT_MAP);
	while (*line)
	{
		if (ft_strchr("01NSWE", *line))
			return (THIS_IS_MAP);
		line++;
	}
	return (THIS_IS_NOT_MAP);
}

int	line_is_empty(char *line)
{
	while (*line)
	{
		if (*line != ' ' && *line != '\t' && *line != '\n')
			return (LINE_HAS_CHAR);
		line++;
	}
	return (LINE_IS_EMPTY);
}

void	normalize_map(t_config *config)
{
	int		max_len;
	int		i;
	int		len;
	char	*new_line;

	max_len = 0;
	i = 0;
	while (config->map[i])
	{
		len = ft_strlen(config->map[i]);
		if (len > max_len)
			max_len = len;
		i++;
	}
	i = 0;
	len = 0;
	while (config->map[i])
	{
		len = ft_strlen(config->map[i]);
		if (len < max_len)
		{
			new_line = malloc(max_len + 1);
			ft_memcpy(new_line, config->map[i], len);
			ft_memset(new_line + len, ' ', max_len - len);
			new_line[max_len] = '\0';
			free(config->map[i]);
			config->map[i] = new_line;
		}
		i++;
	}
}

void	parse_map_line(t_config *config, int fd, char *first_line)
{
	char **map;
	char *line;
	int capa = 8;
	int count = 0;

	map = malloc(sizeof(char *) * capa);
	if (!map)
		exit(1);
	map[count++] = ft_strdup(first_line);
    //\nのトリムをする
	while (get_next_line(fd, &line) > 0)
	{
		if (line_is_empty(line))
		{
			free(line);
			break ;
		}
		if (count > capa)
		{
			capa *= 2;
			map = realloc_2d(map, count, capa);
		}
		map[count++] = ft_strdup(line);
		free(line);
	}
	map[count] = NULL;
	config->map = map;
    config->map_height = count;
}
