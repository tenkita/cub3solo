#include "cub3d.h"

//壁に囲まれているか
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
			if (ft_strchr("0NSWE", map[y][x]))
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
			if (ft_strchr("NSEW", map[y][x]))
				count++;
			x++;
		}
		y++;
	}
	return (count == 1);
}

// parse_map_lineで改行文字をトリムする
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
			if (!ft_strchr("01NSEW \n", map[y][x]))
			{
				printf("Invalid char: [%c] (ascii: %d) at (%d,%d)\n", map[y][x],
					map[y][x], y, x);
				return (CHAR_IS_INVALID);
			}
			x++;
		}
		y++;
	}
	return (CHAR_IS_VALID);
}

int	put_error(const char *msg)
{
	ft_putendl_fd((char *)msg, 2);
	return (0);
}

int	valid_map(char **map)
{
	if (check_map_closed(map) == MAP_IS_UNCLOSED)
		return (put_error("Map is not closed"));
	if (check_player(map) == INVALID_NUM_PLAYER)
		return (put_error("There must be only one player"));
	if (check_invalid_char(map) == CHAR_IS_INVALID)
		return (put_error("Invalid char in map"));
	return (MAP_IS_VALID);
}
