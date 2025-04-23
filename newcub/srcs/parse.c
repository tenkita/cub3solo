/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkitago <tkitago@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/23 13:01:38 by tkitago           #+#    #+#             */
/*   Updated: 2025/04/23 21:37:04 by tkitago          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void		clean_config(t_config *config);
void		free_map(char **map);
void		free_texture(t_config *config);

void	init_texture_color(t_config *config)
{
	config->ceiling_color = -1;
	config->floor_color = -1;
	config->texture_no = NULL;
	config->texture_so = NULL;
	config->texture_we = NULL;
	config->texture_ea = NULL;
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

// return 1 if direction in line
int	is_texture_line(char *line)
{
	while (*line == ' ' || *line == '\t')
		line++;
	return (!strncmp(line, "NO ", 3) || !strncmp(line, "SO ", 3)
		|| !strncmp(line, "WE ", 3) || !strncmp(line, "EA ", 3));
}

// return 1 if F/C in line
int	is_color_line(char *line)
{
	while (*line == ' ' || *line == '\t')
		line++;
	return (line[0] == 'F' || line[0] == 'C');
}

void	exit_parse_texture_error(t_config *config, char *line)
{
	free(line);
	free_texture(config);
	exit(put_error("Duplicate texture"));
}
void	parse_texture_line(t_config *config, char *line)
{
	if (!strncmp(line, "NO ", 3))
	{
		if (config->texture_no != NULL)
			exit_parse_texture_error(config, line);
		config->texture_no = ft_strtrim(line + 3, " \n\t\r");
	}
	else if (!strncmp(line, "SO ", 3))
	{
		if (config->texture_so)
			exit_parse_texture_error(config, line);
		config->texture_so = ft_strtrim(line + 3, " \n\t\r");
	}
	else if (!strncmp(line, "WE ", 3))
	{
		if (config->texture_we)
			exit_parse_texture_error(config, line);
		config->texture_we = ft_strtrim(line + 3, " \n\t\r");
	}
	else if (!strncmp(line, "EA ", 3))
	{
		if (config->texture_ea)
			exit_parse_texture_error(config, line);
		config->texture_ea = ft_strtrim(line + 3, " \n\t\r");
	}
}

//スペース＆文字atoi

int	atoi_check(const char *str)
{
	long long	res;
	int			saw_digit;

	res = 0;
	saw_digit = 0;
	while (*str == ' ' || (*str >= 9 && *str <= 13))
		str++;
	while (*str >= '0' && *str <= '9')
	{
		saw_digit = 1;
		res = res * 10 + (*str - '0');
		if (res > INT_MAX)
			return (-1);
		str++;
	}
	if (!saw_digit)
		return (-1);
	while (*str == ' ' || (*str >= 9 && *str <= 13))
		str++;
	if (*str != '\0')
		return (-1);
	return ((int)res);
}

void	check_floor_ceiling(t_config *config, char *line)
{
	if (line[0] == 'F' && config->floor_color != -1)
	{
		free(line);
		exit(put_error("Duplicate floor color"));
	}
	if (line[0] == 'C' && config->ceiling_color != -1)
	{
		free(line);
		exit(put_error("Duplicate ceiling color"));
	}
}

char	**split_color(char *line)
{
	char	**split;
	int		count;

	count = 0;
	line[strcspn(line, "\r\n")] = '\0';
	split = ft_split(line + 2, ',');
	while (split[count])
		count++;
	if (count != 3)
	{
		free(line);
		free_2d(split);
		exit(put_error("color format: R, G, B"));
	}
	return (split);
}

void	validate_color(char **split)
{
	int	i;

	i = 0;
	while (i < 3)
	{
		if (!split[i] || !*split[i])
		{
			free_2d(split);
			exit(put_error("invalid color format"));
		}
		i++;
	}
}

void	parse_color_line(t_config *config, char *line)
{
	char	**split;
	int		r;
	int		g;
	int		b;
	int		color;

	check_floor_ceiling(config, line);
	split = split_color(line);
	validate_color(split);
	r = atoi_check(split[0]);
	g = atoi_check(split[1]);
	b = atoi_check(split[2]);
	if (r < 0 || r > 255 || g < 0 || g > 255 || b < 0 || b > 255)
	{
		free_2d(split);
		free(line);
		free_texture(config);
		exit(put_error("RGB is out of range"));
	}
	color = (r << 16) | (g << 8) | b;
	if (line[0] == 'F')
		config->floor_color = color;
	else if (line[0] == 'C')
		config->ceiling_color = color;
	free_2d(split);
}

// find start point
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
		if (strchr("01NSWE", *line))
			return (THIS_IS_MAP);
		line++;
	}
	return (THIS_IS_NOT_MAP);
}

char	**alloc_map(size_t *capa)
{
	char	**map;

	*capa = 8;
	map = malloc(sizeof(char *) * (*capa));
	if (!map)
		exit(1);
	return (map);
}

void	append_line(char ***map, size_t *count, size_t *capa, char *line)
{
	if (*count >= *capa)
	{
		*capa *= 2;
		*map = realloc_2d(*map, *count, *capa);
	}
	(*map)[(*count)++] = ft_strdup(line);
}

void	parse_map_line(t_config *config, int fd, char *first_line)
{
	size_t	capa;
	size_t	count;
	char	**map;
	char	*line;

	count = 0;
	map = alloc_map(&capa);
	map[count++] = ft_strdup(first_line);
	while (get_next_line(fd, &line) > 0)
	{
		if (line_is_empty(line))
			break ;
		append_line(&map, &count, &capa, line);
		free(line);
	}
	free(line);
	map[count] = NULL;
	config->map = map;
	config->map_height = count;
	// free_2d(map); //
}

int	find_max_len(t_config *config)
{
	int	i;
	int	max_len;
	int	len;

	max_len = 0;
	len = 0;
	i = 0;
	while (config->map[i])
	{
		len = strlen(config->map[i]);
		if (len > max_len)
			max_len = len;
		i++;
	}
	return (max_len);
}

void	normalize_map(t_config *config)
{
	int		max_len;
	int		i;
	int		len;
	char	*new_line;

	max_len = find_max_len(config);
	i = 0;
	while (config->map[i])
	{
		len = strlen(config->map[i]);
		if (len < max_len)
		{
			new_line = malloc(max_len + 1);
			if (!new_line)
				exit(1);
			memcpy(new_line, config->map[i], len);
			memset(new_line + len, ' ', max_len - len);
			new_line[max_len] = '\0';
			free(config->map[i]);
			config->map[i] = new_line;
		}
		i++;
	}
}

// is it surrounded?
int	valid_wall(char **map, int x, int y)
{
	if (y == 0 || x == 0 || !map[y + 1] || !map[y][x + 1])
		return (UNSURROUNDED_WALL);
	if (map[y - 1][x] == ' ' || map[y + 1][x] == ' ' || map[y][x - 1] == ' '
		|| map[y][x + 1] == ' ')
		return (UNSURROUNDED_WALL);
	return (SURROUNDED_WALL);
}

int	check_map_closed(char **map)
{
	int	y;
	int	x;

	y = 0;
	while (map[y])
	{
		x = 0;
		while (map[y][x])
		{
			if (strchr("0NSWE", map[y][x]))
			{
				if (valid_wall(map, x, y) == UNSURROUNDED_WALL)
					return (MAP_IS_UNCLOSED);
			}
			x++;
		}
		y++;
	}
	return (MAP_IS_CLOSED);
}

// valid num&NSWE
int	check_player(char **map)
{
	int	count;
	int	y;
	int	x;

	count = 0;
	y = 0;
	while (map[y])
	{
		x = 0;
		while (map[y][x])
		{
			if (strchr("NSWE", map[y][x]))
				count++;
			x++;
		}
		y++;
	}
	return (count == 1);
}

int	check_invalid_char(char **map)
{
	int	y;
	int	x;

	y = 0;
	while (map[y])
	{
		x = 0;
		while (map[y][x])
		{
			if (!strchr("01NSWE \n", map[y][x]))
			{
				printf("Invalid char: [%c] (ascii: %d) at (%d, %d)\n",
					map[y][x], map[y][x], y, x);
				return (CHAR_IS_INVALID);
			}
			x++;
		}
		y++;
	}
	return (CHAR_IS_VALID);
}

int	valid_map(char **map)
{
	if (check_map_closed(map) == MAP_IS_UNCLOSED)
		return (put_error("Map is not closed"));
	if (check_player(map) == INVALID_PLAYER)
		return (put_error("There must be only one player"));
	if (check_invalid_char(map) == CHAR_IS_INVALID)
		return (put_error("Invalid char in map"));
	return (MAP_IS_VALID);
}

void	set_player_dir_util(t_config *config, char dir)
{
	if (dir == 'N')
	{
		config->dir_y = -1;
		config->plane_x = 0.66;
	}
	else if (dir == 'S')
	{
		config->dir_y = 1;
		config->plane_x = -0.66;
	}
	else if (dir == 'W')
	{
		config->dir_x = -1;
		config->plane_y = -0.66;
	}
	else if (dir == 'E')
	{
		config->dir_x = 1;
		config->plane_y = 0.66;
	}
}

void	set_player_dir(t_config *config, char dir)
{
	config->dir_x = 0;
	config->dir_y = 0;
	config->plane_x = 0;
	config->plane_y = 0;
	set_player_dir_util(config, dir);
}

void	init_player(t_config *config)
{
	int	y;
	int	x;

	y = 0;
	while (config->map[y])
	{
		x = 0;
		while (config->map[y][x])
		{
			if (strchr("NSWE", config->map[y][x]))
			{
				config->player_x = x + 0.5;
				config->player_y = y + 0.5;
				set_player_dir(config, config->map[y][x]);
				config->map[y][x] = '0';
				return ;
				printf("%f\n", config->player_x);
			}
			x++;
		}
		y++;
	}
}

void	check_color(t_config *config)
{
	if (!config->texture_no || !config->texture_so || !config->texture_we
		|| !config->texture_ea || config->floor_color == -1
		|| config->ceiling_color == -1)
	{
		clean_config(config);
		exit(put_error("Missing element in .cub file"));
	}
}

t_config	parse_map(char *file)
{
	t_config	config;
	int			fd;
	char		*line;

	init_texture_color(&config);
	fd = open(file, O_RDONLY);
	if (fd < 0)
		perror("Error open .cub file");
	while (get_next_line(fd, &line) > 0)
	{
		if (line_is_empty(line) == LINE_HAS_CHAR)
		{
			if (is_texture_line(line))
				parse_texture_line(&config, line);
			else if (is_color_line(line))
				parse_color_line(&config, line);
			else if (is_map_line(line) == THIS_IS_MAP)
			{
				parse_map_line(&config, fd, line);
				normalize_map(&config);
				// mapのながさが違うときどう対処する
				if (valid_map(config.map) == MAP_IS_INVALID)
				{
					free(line);
					clean_config(&config);
					exit(EXIT_FAILURE);
				}
				init_player(&config);
				// break ;
			}
		}
		free(line);
	}
	free(line);
	check_color(&config);
	return (config);
}

// void	normalize_map(t_config *config)
// {
// 	int		max_len;
// 	int		i;
// 	int		len;
// 	char	*new_line;

// 	max_len = 0;
// 	i = 0;
// 	while (config->map[i])
// 	{
// 		len = strlen(config->map[i]);
// 		if (len > max_len)
// 			max_len = len;
// 		i++;
// 	}
// 	i = 0;
// 	len = 0;
// 	while (config->map[i])
// 	{
// 		len = strlen(config->map[i]);
// 		if (len < max_len)
// 		{
// 			new_line = malloc(max_len + 1);
// 			memcpy(new_line, config->map[i], len);
// 			memset(new_line + len, ' ', max_len - len);
// 			new_line[max_len] = '\0';
// 			free(config->map[i]);
// 			config->map[i] = new_line;
// 		}
// 		i++;
// 	}
// }