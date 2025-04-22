
#include "cub3d.h"

int	is_texture_line(char *line)
{
	while (*line == ' ' || *line == '\t')
		line++;
	return (!strncmp(line, "NO ", 3) || !strncmp(line, "SA ", 3)
		|| !strncmp(line, "WE ", 3) || !strncmp(line, "EA ", 3));
}

void	parse_texture_line(t_config *config, char *line)
{
	// char	*path;
	if (!strncmp(line, "NO ", 3))
	{
		if (config->texture_no)
			exit(put_error("Duplicate texture: NO"));
		// path = ft_strtrim(line + 3, " \n\t\r");
		// printf("Loaded texture path: [%s]\n", path);
		// config->texture_no = path;
		config->texture_no = ft_strtrim(line + 3, " \n\t\r");
		// if (access(path, F_OK) != 0)
		//     printf("file not found: %s", path);
		// else
		//     printf("nice\n");
	}
	else if (!strncmp(line, "SO ", 3))
	{
		if (config->texture_so)
			exit(put_error("Duplicate texture: SO"));
		config->texture_so = ft_strtrim(line + 3, " \n\t\r");
	}
	else if (!strncmp(line, "WE ", 3))
	{
		if (config->texture_we)
			exit(put_error("Duplicate texture: WE"));
		config->texture_we = ft_strtrim(line + 3, " \n\t\r");
	}
	else if (!strncmp(line, "EA ", 3))
	{
		if (config->texture_ea)
			exit(put_error("Duplicate texture: EA"));
		config->texture_ea = ft_strtrim(line + 3, " \n\t\r");
	}
}

int	is_color_line(char *line)
{
	while (*line == ' ' || *line == '\t')
		line++;
	return (line[0] == 'F' || line[0] == 'C');
}

void	parse_color_line(t_config *config, char *line)
{
	char	**split;
	int		color;

	int r, g, b;
	if (line[0] == 'F' && config->floor_color != -1)
		exit(put_error("Duplicate floor color"));
	if (line[0] == 'C' && config->ceiling_color != -1)
		exit(put_error("Duplicate ceiling color"));
	split = ft_split(line + 2, ',');
	if (!split || !split[0] || !split[1] || !split[2])
		exit(put_error("invalid color format"));
	r = ft_atoi(split[0]);
	g = ft_atoi(split[1]);
	b = ft_atoi(split[2]);
	if (r < 0 || r > 255 || g < 0 || g > 255 || b < 0 || b > 255)
		exit(put_error("RGB is out of range"));
	color = (r << 16) | (g << 8) | b;
	if (line[0] == 'F')
		config->floor_color = color;
	else
		config->ceiling_color = color;
	free_2d(split);
}

void	init_texture_color(t_config *config)
{
	config->ceiling_color = -1;
	config->floor_color = -1;
	config->texture_no = NULL;
	config->texture_so = NULL;
	config->texture_we = NULL;
	config->texture_ea = NULL;
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
				if (valid_map(config.map) == MAP_IS_INVALID)
					exit(EXIT_FAILURE);
				init_player(&config);
				break ;
			}
		}
		free(line);
	}
	return (config);
}

// void	parse_texture_line(t_config *config, char *line)
// {
//     //printf("inparse_texture\n");
// 	if (!strncmp(line, "NO ", 3))
// 		{config->texture_no = ft_strdup(line + 3);
//             }
// 	else if (!strncmp(line, "SO ", 3))
// 		config->texture_so = ft_strdup(line + 3);
// 	else if (!strncmp(line, "WE ", 3))
// 		config->texture_we = ft_strdup(line + 3);
// 	else if (!strncmp(line, "EA ", 3))
// 		{config->texture_ea = ft_strdup(line + 3);
//     }
// }