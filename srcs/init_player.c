#include "cub3d.h"

void	set_player_dir(t_config *config, char dir)
{
	if (dir == 'N')
	{
		config->dir_x = 0;
		config->dir_y = -1;
		config->plane_x = 0.66;
		config->plane_y = 0;
	}
	else if (dir == 'S')
	{
		config->dir_x = 0;
		config->dir_y = 1;
		config->plane_x = -0.66;
		config->plane_y = 0;
	}
	else if (dir == 'E')
	{
		config->dir_x = 1;
		config->dir_y = 0;
		config->plane_x = 0;
		config->plane_y = 0.66;
	}
	else if (dir == 'W')
	{
		config->dir_x = -1;
		config->dir_y = 0;
		config->plane_x = 0;
		config->plane_y = -0.66;
	}
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
			if (ft_strchr("NSEW", config->map[y][x]))
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
